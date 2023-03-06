/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:58:35 by pvong             #+#    #+#             */
/*   Updated: 2023/03/06 13:15:57 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_filepath(char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	return (env[i] + 5);
}

char	*get_cmds_path(char *cmds, char **env)
{
	int		i;
	char	*file_path;
	char	**path;

	i = 0;
	file_path = get_filepath(env);
	path = ft_split(file_path, ':');

	while (path[i])
	{
		if (access)
	}
	free_split(path);
}