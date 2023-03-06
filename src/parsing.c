/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:58:35 by pvong             #+#    #+#             */
/*   Updated: 2023/03/06 03:15:15 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_filepath(char *name, char **env)
{
	int		i;
	int		j;
	char	*path;
	
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		path = ft_substr(env[i], 0, j);
		if (ft_strcmp(path, name) == 0)
		{
			free(path);
			return (env[i] + j + 1);
		}
		free(path);
		++i;
	}
	return (NULL);
}

char	*get_path(char *cmds, char **env)
{
	int		i;
	char	**split_path;
	char	*to_execve;
	char	*path;

	i = 0;
	split_path = ft_split(get_filepath("PATH", env), ':');
	while (split_path[i])
	{
		path = ft_strjoin(split_path[i], "/");
		to_execve = ft_strjoin(path, cmds);
		free(path);
		if (access(to_execve, F_OK | X_OK) == 0)
		{
			free_split(split_path);
			return (to_execve);
		}
		free(to_execve);
		++i;
	}
	free_split(split_path);
	return (cmds);
}