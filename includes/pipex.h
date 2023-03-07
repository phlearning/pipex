/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:24 by pvong             #+#    #+#             */
/*   Updated: 2023/03/07 18:16:32 by pvong            ###   ########.fr       */
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

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**env;
	char	**cmd_path;
	char	***cmd;
	int		fd[2];
}	t_data;

/* Utils */

int		my_open(char *file_name, int flag);
int		ft_strcmp(char *s1, char *s2);
void	free_split(char **split);
void	printsplit(char **env);
void	free_cmds(char ***cmd);
t_data	init_data(int ac, char **av, char **env);

/* Parsing */

char	*get_filepath(char **env);
char	*get_cmds_path(char *cmds, char **env);

/* Process */

void	my_execve(int ac, char **cmds, char **env);
void	child_process(t_data data);
void	parent_process(t_data data);

#endif