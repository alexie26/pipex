/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:03:25 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/16 16:43:08 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_fetus(t_pipex *pipex)
{
	char	*cmd;

	dup2(pipex->pipex_fd[1], 1);
	close(pipex->pipex_fd[0]);
	dup2(pipex->infile, 0);
	cmd = find_cmd(pipex->path, pipex->cmd1[0]);
	if (!cmd)
	{
		free_fetus(pipex);
		perror("Bad command!");
		exit(127);
	}
	execve(cmd, pipex->cmd1, pipex->env);
	perror("fetus eorror");
	free_fetus(pipex);
	exit(126);
}

void	second_fetus(t_pipex *pipex)
{
	char	*cmd;

	dup2(pipex->pipex_fd[0], 0);
	close(pipex->pipex_fd[1]);
	dup2(pipex->outfile, 1);
	cmd = find_cmd(pipex->path, pipex->cmd2[0]);
	if (!cmd)
	{
		free_fetus(pipex);
		perror("Bad command!");
		exit(127);
	}
	execve(cmd, pipex->cmd2, pipex->env);
	perror("fetus eorror");
	free_fetus(pipex);
	exit(126);
}
