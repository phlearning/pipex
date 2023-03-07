/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:01 by pvong             #+#    #+#             */
/*   Updated: 2023/03/07 18:17:39 by pvong            ###   ########.fr       */
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

t_data	init_data(int ac, char **av, char **env)
{
	t_data	data;
	int		i;

	i = 1;
	data.cmd = malloc(sizeof(char **) * (ac - 3));
	if (!data.cmd)
		exit(1);
	while (++i < ac - 1)
		data.cmd[i - 2] = ft_split(av[i], ' ');
	data.cmd_path = malloc(sizeof(char *) * (ac - 3));
	if (!data.cmd_path)
		exit(1);
	i = 1;
	while (++i < ac - 1)
		data.cmd_path[i - 2] = get_cmds_path(data.cmd[i - 2][0], env);
	data.ac = ac;
	data.av = av;
	data.env = env;
	return (data);
}

int	main(int ac, char **av, char **env)
{
	int		pid;
	t_data	data;

	if (ac < 5)
	{
		perror("./pipex infile cmds1 cmds2 outfile");
		exit(1);
	}
	data = init_data(ac, av, env);
	if (pipe(data.fd) == -1)
	{
		perror("Error pipe()");
		exit(-1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error fork()");
		exit(0);
	}
	if (pid == 0)
		child_process(data);
	else
		parent_process(data);
	return (0);
}

/* int	main(int ac, char **av, char **env)
{
	(void) 	ac;
	(void) 	av;
	t_data	data;

	if (ac >= 3)
	{
		data.cmd = malloc(sizeof(char **) * (ac - 3));
		data.cmd[0] = ft_split(av[2], ' ');
		data.cmd_path = get_cmds_path(data.cmd[0][0], env);
		ft_printf("--------\n");
		ft_printf("cmdspath: %s\n", data.cmd_path);
		execve(data.cmd_path, data.cmd[0], env);
	}
	free(data.cmd_path);
	free_cmds(data.cmd);
} */