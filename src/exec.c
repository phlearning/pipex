/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:53:14 by pvong             #+#    #+#             */
/*   Updated: 2023/03/13 13:48:33 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * cmd_av is respectively av[2] ... av[ac - 2]
 * cmds_tab is the commands and its flags;
 * For example cmds_tab[2] = {"ls", "-l"};
 * 
 * Get the cmds;
 * Look for its path;
 * Execute the commands;
 * if not exit;
 * @param cmd_av 
 * @param env 
 */
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

/**
 * Pipe the fd (allocates a pair of fd and allow a one way data flow);
 * fd[0] -> connect to the read end of the pipe
 * fd[1] -> connects to the write end
 * Fork dupe the process; Child pid == 0; Parent pid > 0; 
 * Pid == -1 indicates an error to the fork;
 * @param cmd 
 * @param env 
 */
void	pipe_exec(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_error("Error Pipe()");
	pid = fork();
	if (pid < 0)
		exit_error("Error Fork()");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		my_execve(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

/**
 * Create the outfile;
 * I is the index of the commands; 
 * av[2] is the first commands;
 * av[ac - 2] the last one;
 * Pipe the commands and execute them;
 * @param ac 
 * @param av 
 * @param env 
 */
void	pipe_cmd(int ac, char **av, char **env)
{
	int	outfile_fd;
	int	i;

	outfile_fd = my_open(av[ac - 1], 1);
	i = 2;
	while (i < ac - 2)
		pipe_exec(av[i++], env);
	dup2(outfile_fd, STDOUT_FILENO);
	my_execve(av[ac - 2], env);
}
