/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:58:35 by pvong             #+#    #+#             */
/*   Updated: 2023/03/12 20:32:21 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	char	*tmp;
	char	*cmdpath;

	i = -1;
	file_path = get_filepath(env);
	path = ft_split(file_path, ':');
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		cmdpath = ft_strjoin(tmp, cmds);
		free(tmp);
		if (access(cmdpath, F_OK) == 0)
		{
			free_split(path);
			return (cmdpath);
		}
		free(cmdpath);
	}
	free_split(path);
	perror("Error Command Not Found");
	return (0);
}
