/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:53:14 by pvong             #+#    #+#             */
/*   Updated: 2023/03/06 12:40:49 by pvong            ###   ########.fr       */
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
// void	my_execve(char *cmds, char **env)
// {
// 	char	**cmds_flags;
// 	char	*path;

// }

// void	child_process(int *fd, char **av, char **env)
// {
// 	int	child_fd;

// 	child_fd = my_open(av[1], 0);
// 	dup2(fd[1], STDOUT_FILENO);
// 	dup2(child_fd, STDIN_FILENO);
// 	close(fd[0]);
//  my_execve();
//	perror("Error");
// }

// void	parent_process(int *fd, char **av, char **env)
// {
// 	int	parent_fd;

// 	parent_fd = my_open(av[1], 1);

// }