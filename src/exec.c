/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:53:14 by pvong             #+#    #+#             */
/*   Updated: 2023/03/12 20:22:15 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_execve(char *cmd_av, char **env)
{
	char	*path;
	char	**cmds_tab;

	cmds_tab = ft_split(cmd_av, ' ');
	if (access(cmds_tab[0], F_OK) == 0)
		path = cmds_tab[0];
	else
		path = get_cmds_path(cmds_tab[0], env);
	if (path == NULL)
	{
		free_split(cmds_tab);
		exit(1);
	}
	if (execve(path, cmds_tab, env) == -1)
	{
		perror("Error Execve()");
		free_split(cmds_tab);
		free(path);
		exit(1);
	}
}

void	pipe_exec(char *cmd, char **env)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		exit_error("Error Pipe()");
	pid = fork();
	if (pid < 0)
		exit_error("Error Fork()");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		my_execve(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
}

void	pipe_cmd(int ac, char **av, char **env)
{
	int	outfile_fd;
	int	here_doc;
	int	i;

	here_doc = 0;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		outfile_fd = my_open(av[ac - 1], 2);
		here_doc = 1;
	}
	else
		outfile_fd = my_open(av[ac - 1], 1);
	i = 2 + here_doc;
	while (i < ac - 2)
		pipe_exec(av[i++], env);
	dup2(outfile_fd, STDOUT_FILENO);
	my_execve(av[ac - 2], env);
}
