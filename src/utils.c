/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:56:16 by pvong             #+#    #+#             */
/*   Updated: 2023/03/13 13:18:43 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Open according the file (infile or outfile)
 * If failed to open, exit the program.
 * 0 to Read_only, 1 to CREAT|WRONLY|TRUNC.
 * 2 to CREAT|WRONLY|APPEND.
 * @param file_name 
 * @param endpoint 
 * @return int 
 */
int	my_open(char *file_name, int flag)
{
	int	opened;

	if (flag == 0)
		opened = open(file_name, O_RDONLY);
	if (flag == 1)
		opened = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (flag == 2)
		opened = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if (opened == -1 && flag == 0)
	{
		perror("Error");
		exit(0);
	}
	if (opened == -1 && (flag == 1 || flag == 2))
	{
		perror("Error");
		exit(1);
	}
	return (opened);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	if (!split)
		return ;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	printsplit(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		ft_printf("env[%d]: %s\n", i, env[i]);
}

void	free_cmds(char ***cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free_split(cmd[i]);
	free(cmd);
}

void	exit_error(char *str)
{
	perror(str);
	exit(1);
}
