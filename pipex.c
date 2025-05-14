/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:31:36 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/14 17:21:08 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	check_argv(int argc, char **argv)
// {
// 	if (argc < 5)
// 	{
// 		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n");
// 	}
// }

// t_pipex *ft_init(int argc, char **argv, char **env)
// {
// 	t_pipex *pipex;

	
// }

char *find_path(char **env)
{
	int	i;
	int	j;
	char *path;

	path = "PATH";
	i = 0;
	while (*env[i])
	{
		j = 0;
		while (path[j] && path[j] == env[i][j])
		{
			if (!path[j + 1])
				return (&env[i][j + 1]); //value after PATH
			j++;
		}
		i++;
	}
	return (NULL);
}
char *find_cmd(char **path, char *cmd)
{
	char *temp;
	char *full_cmd;

	while (*path)
	{
		temp = ft_strjoin(*path, "/"); //adding the slash so they wont be joined
		full_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_cmd, 0) == 0)
			return (full_cmd);
		free(full_cmd);
		path++;
	}
	return (NULL);
}

char *get_cmd_path(char *cmd, char **env)
{
	char *path_env;
	char **path;
	char *cmd_path;
	
	path_env = find_path(env);
	if (!path_env)
		return (NULL);
	path = ft_split(path_env, ':');
	cmd_path = find_cmd(path, cmd);
	free(path);
	return (cmd_path);
}
//path countains /usr/bin:/bin:/etcccc......
//find_cmd so i have the correct path towards the command

void	first_fetus(t_pipex *pipex)
{
	char	*cmd;

	dup2(pipex->pipex_fd[1], 1);
	close(pipex->pipex_fd[0]);
	dup2(pipex->infile, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex			*pipex;
	pid_t			pid1;
	pid_t			pid2;
	char			*cmd_path;
	
	if (argc != 5)
		perror("Wrong amount of arguments :< ");
	pid1 = fork();
	cmd_path = get_cmd_path(argv[1], env);
    if (cmd_path)
    {
        ft_printf("Command found: %s\n", cmd_path);
        free(cmd_path);
    }
    else
        ft_putstr_fd("Command not found\n", 2);

    return (0);
}
