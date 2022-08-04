/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:47:21 by pwhittin          #+#    #+#             */
/*   Updated: 2022/08/04 16:36:50 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_read_and_save(fd, *save)
{
	char	*buf;
	char	c;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	c = 1;
	while (!ft_strchr(save, '\n') && c != 0)
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c == -1)
		{
			free(buf);
			return (NULL);
		}
	}
}

/*char	*ft_get_line(*save)
{

}

char	*ft_save(*save)
{

}*/

int	get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return NULL;
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
