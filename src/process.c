/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:53:14 by pvong             #+#    #+#             */
/*   Updated: 2023/03/06 03:21:06 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Look for the cmds and its flags.
 * Look for the path.
 * Execute the cmds.
 * @param cmds 
 * @param env 
 */
void	my_execve(char *cmds, char **env)
{
	char	**cmds_flags;
	char	*path;

	cmds_flags = ft_split(cmds, ' ');
	path = get_path(cmds_flags[0], env);
	if (execve(path, cmds_flags, env) == -1)
	{
		perror("Command not found\n");
		free_split(cmds_flags);
		free(path);
		exit(0);
	}
}

void	child_process(int *fd, char **av, char **env)
{
	int	child_fd;

	child_fd = my_open(av[1], 0);
	dup2(child_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	my_execve(av[2], env);
}

void	parent_process(int *fd, char **av, char **env)
{
	int	parent_fd;

	parent_fd = my_open(av[4], 1);
	dup2(parent_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	my_execve(av[3], env);
}