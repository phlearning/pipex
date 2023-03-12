/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:24 by pvong             #+#    #+#             */
/*   Updated: 2023/03/12 19:14:50 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

/* Utils */

int		my_open(char *file_name, int flag);
void	free_split(char **split);
void	printsplit(char **env);
void	free_cmds(char ***cmd);
void	exit_error(char *str);

/* Parsing */

char	*get_filepath(char **env);
char	*get_cmds_path(char *cmds, char **env);

/* Process */

void	my_execve(char *cmd_av, char **env);
void	pipe_exec(char *cmd, char **env);
void	pipe_cmd(int ac, char **av, char **env);

/* ------ Bonus ------ */

/* Here_doc */

void	here_doc(int ac, char **av);
void	input_here_doc(char **av, int *fd);

#endif