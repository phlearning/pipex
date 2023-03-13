/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:58:35 by pvong             #+#    #+#             */
/*   Updated: 2023/03/13 13:56:50 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Look for "PATH" in env
 * and return the corresponding path_line;
 * @param env 
 * @return char* 
 */
char	*get_filepath(char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	return (env[i] + 5);
}

/**
 * Get the line and separate it by ":";
 * Add "/" at the end of the path;
 * Add the cmd to the path;
 * Check for access to the cmd;
 * Return cmd path;
 * @param cmds 
 * @param env 
 * @return char* 
 */
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
