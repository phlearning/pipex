/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:01 by pvong             #+#    #+#             */
/*   Updated: 2023/03/10 13:49:02 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

	


	return (0);
}
