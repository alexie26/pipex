/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:15:07 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/16 16:23:43 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_fetus(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	if (pipex->cmd1)
		free_split(pipex->cmd1);
	if (pipex->cmd2)
		free_split(pipex->cmd2);
	if (pipex->path)
		free_split(pipex->path);
	free(pipex);
}