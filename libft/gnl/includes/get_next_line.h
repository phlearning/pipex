/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:25:05 by pvong             #+#    #+#             */
/*   Updated: 2022/10/27 13:58:26 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_free_read_error(int fd, char **buffer);
char	*ft_get_line(char **str, char **line);
void	ft_read_line(int fd, char *buffer, char **str);
char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);

#endif
