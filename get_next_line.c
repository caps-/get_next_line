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
