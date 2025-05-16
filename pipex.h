/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:18:11 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/16 16:48:19 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft-42/libft.h"
# include "printf42/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// fork(): create a new process, which is a copy of the current process
//			In the parent process,
				// fork() returns the process ID (PID) of the child process.
//				In the child process, fork() returns 0.
// pipe(): creates a unidirectional communication channel between two processes.
//			data written to one end can be read from another

// 1. create a pipe: one for reading and one for writing
// 2. fork a child process

typedef struct s_pipe
{
	int		pipex_fd[2];
	int		infile;
	int		outfile;
	char	**path;
	char	**env;
	char	**cmd1;
	char	**cmd2;

}			t_pipex;

void		first_fetus(t_pipex *pipex);
void		second_fetus(t_pipex *pipex);

void		free_split(char **split);
void		free_fetus(t_pipex *pipex);

char		*find_path(char **env);
char		*find_cmd(char **path, char *cmd);
char		*get_cmd_path(char *cmd, char **env);

t_pipex		*init(char **argv, char **env);
int			validate_pipex(t_pipex *pipex);

#endif