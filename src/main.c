/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:01 by pvong             #+#    #+#             */
/*   Updated: 2023/03/07 12:18:46 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* int	main()
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		return (1);

	pid1 = fork();
	if (pid1 < 0)
		return (2);

	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls", "-l", NULL);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "includes", NULL);
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
} */

// int	main(int ac, char **av, char **env)
// {
// 	int	fd;
// 	int	pid;

// 	if (ac < 5)
// 		return (0);
// 	if (pipe(fd) == -1)
// 	{
// 		perror("Error pipe()")
// 		exit(-1);
// 	}
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("Error fork()");
// 		exit(0);
// 	}
// 	if (pid == 0)
// 		child_process(fd, av, env);
// 	else
// 		parent_process(fd, av, env);
// 	return (0);
// }

int	main(int ac, char **av, char **env)
{
	(void) 	ac;
	(void) 	av;
	t_data	data;

	data.cmd_path = get_cmds_path(data.cmd[0], env);
	ft_printf("--------\n");
	ft_printf("cmdspath: %s\n", data.cmd_path);
	free(data.cmd_path);
}