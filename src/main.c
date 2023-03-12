/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:01 by pvong             #+#    #+#             */
/*   Updated: 2023/03/12 19:13:45 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	infile_fd;

	if (ac < 5)
		exit(1);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		here_doc(ac, av);
	else
	{
		infile_fd = my_open(av[1], 0);
		dup2(infile_fd, 0);
	}
	pipe_cmd(ac, av, env);
	return (0);
}
