/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:01 by pvong             #+#    #+#             */
/*   Updated: 2023/03/06 12:48:15 by pvong            ###   ########.fr       */
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
	(void) ac;
	(void) av;
	// printsplit(env);

	char	**path;
	char *path_to_bin;
	path_to_bin = get_filepath(env);
	ft_printf("path: %s\n", path_to_bin);
	ft_printf("--------\n");
	path = ft_split(path_to_bin, ':');
	printsplit(path);

	free_split(path);
}