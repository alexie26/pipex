/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:31:36 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/16 16:40:21 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*init(char **argv, char **env)
{
	t_pipex	*pipex;

	pipex = ft_calloc(sizeof(t_pipex), 1);
	if (!pipex)
		return (perror("Error malloc"), free_fetus(pipex), NULL);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		return (perror("Error read file"), free(pipex), NULL);
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->outfile < 0)
		return (perror("Error openin output file"), close(pipex->infile),
			free(pipex), NULL);
	pipex->path = ft_split(find_path(env), ':');
	if (!pipex->path)
		return (perror("Error split"), close(pipex->infile),
			close(pipex->outfile), free(pipex), NULL);
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (!pipex->cmd1 || !pipex->cmd2)
		return (perror("Error splitting commands"), pipex);
	if (pipe(pipex->pipex_fd) < 0)
		return (perror("pipe err"), pipex);
	pipex->env = env;
	return (pipex);
}

int	validate_pipex(t_pipex *pipex)
{
	if (!pipex || !pipex->cmd1 || !pipex->cmd2 || !pipex->path)
	{
		free_fetus(pipex);
		return (0);
	}
	return (1);
}

// void	leaks(void)
// {
// 	system("leaks pipex");
// }

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		perror("Wrong amount of arguments :< ");
		return (127);
	}
	pipex = init(argv, env);
	if (!validate_pipex(pipex))
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("fetus deletus"), free_fetus(pipex), 1);
	if (pid1 == 0)
		first_fetus(pipex);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork error"), free_fetus(pipex), 1);
	if (pid2 == 0)
		second_fetus(pipex);
	return (close(pipex->pipex_fd[0]), close(pipex->pipex_fd[1]), waitpid(pid1,
			NULL, 0), waitpid(pid2, NULL, 0), free_fetus(pipex), 1);
}
