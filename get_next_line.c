/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:47:21 by pwhittin          #+#    #+#             */
/*   Updated: 2022/08/03 15:47:23 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_read_and_save(fd, *save)
{

}

char	*ft_get_line(*save)
{

}

char	*ft_save(*save)
{

}

int	get_next_line(int fd)
{
	char		*line;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp =ft_read_and_save(fd, save);
	if (!save)
		return NULL;
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
