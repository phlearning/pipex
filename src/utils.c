/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:56:16 by pvong             #+#    #+#             */
/*   Updated: 2023/03/07 16:41:09 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Open according the file (infile or outfile)
 * If failed to open, exit the program.
 * 0 to Read_only, 1 to CREAT|WRONLY|TRUNC.
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
		opened = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (opened == -1)
	{
		perror("Error Open()");
		exit(EXIT_FAILURE);
	}
	return (opened);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
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
