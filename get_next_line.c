/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:23:58 by pwhittin          #+#    #+#             */
/*   Updated: 2022/09/15 17:15:05 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Our function to read from the file desciptor and store it in a buffer.
 *
 * First up we'll use the BUFFER_SIZE passed during compile + 1 extra byte
 * to malloc our tmp variable, + 1 just so we have space at the end for a null
 * terminator. A NULL check, then we init our size variable to 1.
 *
 * Next we go in to a while loop that's going to do it's thing as long as the
 * size variable isn't 0 and it reaches a new line thanks to the buffer being
 * passed to ft_strchr(). Inside the loop we're passing tmp and BUFFER_SIZE
 * to read(), which will both read and store x ammount of bytes in our tmp 
 * variable and return the number of bytes it managed to read to use for our
 * size variable's value. If size happens to then be less than 0 we'll free the
 * memory allocated to tmp and return NULL.
 *
 * Still in the while loop, we'll move to the end of tmp and add a null
 * terminator, and then use ft_strjoin() to join both the buffer and tmp in to
 * a single string. Once that's done we exit the loop before freeing up tmp and
 * returning the buffer.*/

char	*read_fd(int fd, char *buffer)
{
	char	*tmp;
	int		size;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (NULL);
	size = 1;
	while (ft_strchr(buffer) == NULL && size != 0)
	{
		size = read(fd, tmp, BUFFER_SIZE);
		if (size < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[size] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

/* Our function to pull the line from the buffer.
 *
 * Quick null check, then in to a little while loop that counts through the
 * bytes in the buffer and stops when it gets to a new line. Next well use 
 * malloc to allocate memory for our str variable, then a quick check to make 
 * sure it worked that'll return NULL if it doesn't.
 *
 * We'll re-init our counter i, then go in to a while loop that's going to 
 * copy over the contents of str to our buffer until we hit a new line. Then if
 * we're at the new line character in the buffer, we'll finally copy THAT over
 * too, before we finally stick a null terminator on the end of our str and
 * return it. */

char	*get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* This function is used to make a new buffer so if get_next_line() is used
 * again it will pick up where it left off.
 *
 * So first up we'll use our ft_strlen() function to get the entire length of
 * the original buffer and set our k variable to that value. Next we'll count
 * through the buffer with our j variable until it hit's a new line. If we
 * reach a null terminator we free the allocated buffer memory and return NULL.
 *
 * Now that's done we'll malloc some memory for our new buffer. For the size
 * we're subtracting the length of the old new line (heh) from the length of
 * the whole buffer, adding one more byte on the end for a null terminator 
 * later. Likkle null check, then we go in to a simple while loop to copy the 
 * old buffer in to the new one. We add a null terminator on the end, free up 
 * the old buffer and then return the new buffer! */

char	*new_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = ft_strlen(buffer);
	while (buffer[j] && buffer[j] != '\n')
		j++;
	if (buffer[j] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (k - j + 1));
	if (new_buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[j++])
		new_buffer[i++] = buffer[j];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

/* The star of the show. Basically we want to return a single line read from a
 * file descriptor while keeping track of the line after it and using an
 * arbitrary buffer size. If you call the function again it should do
 * the same thing as the first time, but starting from the line following
 * the first one it read.
 *
 * Starting out with a quick null check, making sure there's actually a file
 * descriptor being passed and the buffer size isn't 0 or something negative.
 *
 * Next we'll use our read_fd() function to read from the file descriptor and
 * dump it's ouptut into our buffer variable. If there's nothing there we're
 * just going to return NULL. Then we'll use our get_line() function to
 * actually pull the line from the buffer and store it in our line variable.
 * 
 * Now that's all done we'll use our new_buffer() function to put all the 
 * leftover characters back in to the buffer so we can run get_next_line() 
 * again and it'll pick up where it left off.
 *
 * Finally we'll return the read line.*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_line(buffer);
	buffer = new_buffer(buffer);
	return (line);
}
