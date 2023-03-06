/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:24 by pvong             #+#    #+#             */
/*   Updated: 2023/03/06 03:21:10 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

/* Utils */
int		my_open(char *file_name, int flag);
int		ft_strcmp(char *s1, char *s2);
void	free_split(char **split);

/* Parsing */
char	*get_filepath(char *name, char **env);
char	*get_path(char *cmds, char **env);

/* Process */
void	my_execve(char *cmds, char **env);
void	child_process(int *fd, char **av, char **env);
void	parent_process(int *fd, char **av, char **env);


#endif