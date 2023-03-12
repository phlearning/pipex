/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:11:27 by pvong             #+#    #+#             */
/*   Updated: 2023/03/12 19:25:44 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Input the here_doc to the writing end of the fd;
 * Exit this process once at the end of the doc;
 * @param av 
 * @param fd 
 */
void	input_here_doc(char **av, int *fd)
{
	char	*buf;
	int		len;

	while (1)
	{
		ft_putstr_fd("> ", 1);
		buf = get_next_line(0);
		len = ft_strlen(av[2]);
		if ((!buf) || (ft_strncmp(buf, av[2], len) == 0 && \
			buf[len + 1] == '\0'))
		{
			free(buf);
			exit(1);
		}
		ft_putstr_fd(buf, fd[1]);
		free(buf);
	}
}

/**
 * Duplicate the process.
 * The parent process wait for the child to end;
 * The child read the input of the heredoc.
 * The parent then transfer the here_doc to the standard input.
 * @param ac 
 * @param av 
 */
void	here_doc(int ac, char **av)
{
	int		fd[2];
	pid_t	pid;

	if (ac < 6)
		exit(1);
	if (pipe(fd) == -1)
		exit_error("Error Pipe()");
	pid = fork();
	if (pid < 0)
		exit_error("Error Fork()");
	if (pid == 0)
		input_here_doc(av, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(-1, NULL, 0);
	}
}
