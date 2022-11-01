/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:57:05 by pwhittin          #+#    #+#             */
/*   Updated: 2022/09/06 15:22:45 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_fd(int fd, char *buffer);
char	*get_line(char *buffer);
char	*new_buffer(char *buffer);
char	*new_buffer(char *buffer);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);

#endif
