/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:53:14 by pvong             #+#    #+#             */
/*   Updated: 2023/03/07 19:11:34 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * Look for the cmds and its flags.
 * Look for the path.
 * Execute the cmds.
 * @param cmds 
 * @param env 
 */
void	my_execve(int ac, char **cmds, char **env)
{
	char	*path;

	if (ac < 5)
		exit(1);
	path = get_cmds_path(cmds[0], env);
	execve(path, cmds, env);
	perror("Error execve()");
}

void	child_process(t_data data)
{
	int	child_fd;

	child_fd = my_open(data.av[1], 0);
	dup2(data.fd[1], STDOUT_FILENO);
	dup2(child_fd, STDIN_FILENO);
	close(data.fd[0]);
	close(child_fd);
	my_execve(data.ac, data.cmd[0], data.env);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	parent_process(t_data data)
{
	int	parent_fd;

	parent_fd = my_open(data.av[data.ac - 1], 1);
	dup2(parent_fd, STDOUT_FILENO);
	dup2(data.fd[0], STDIN_FILENO);
	close(data.fd[1]);
	close(parent_fd);
	my_execve(data.ac, data.cmd[1], data.env);
	perror("Error");
	exit(EXIT_FAILURE);
}
