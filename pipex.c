/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:31:36 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/12 16:14:44 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipex			*pipex;
	pid_t			pid1;
	pid_t			pid2;
	
	if (argc != 5)
		perror("Wrong amount of arguments :< ");
	pid1 = fork();
	// if (pid1 == 0)
	// {
		
	// }
}