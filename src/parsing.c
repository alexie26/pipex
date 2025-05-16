/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:13:12 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/16 16:23:49 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path(char **env)
{
	int		i;
	int		j;
	char	*path;

	path = "PATH";
	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		j = 0;
		while (path[j] && path[j] == env[i][j])
		{
			if (!path[j + 1])
				return (&env[i][j + 1]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*find_cmd(char **path, char *cmd)
{
	char	*temp;
	char	*full_cmd;

	while (*path)
	{
		temp = ft_strjoin(*path, "/");
		full_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_cmd, 0) == 0)
			return (full_cmd);
		free(full_cmd);
		path++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	*path_env;
	char	**path;
	char	*cmd_path;

	path_env = find_path(env);
	if (!path_env)
		return (NULL);
	path = ft_split(path_env, ':');
	if (!path)
		return (NULL);
	cmd_path = find_cmd(path, cmd);
	free_split(path);
	return (cmd_path);
}
