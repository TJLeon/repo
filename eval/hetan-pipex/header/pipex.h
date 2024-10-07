/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:44 by hetan             #+#    #+#             */
/*   Updated: 2023/12/24 04:47:29 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/wait.h>//wait(), waitpid()
//close() read() write() access() dup() dup2() execve fork() pipe() unlink()
# include <unistd.h>
# include <stdlib.h>//malloc(), free(), exit
# include <string.h>//strerror()
# include <stdio.h>//perror()
# include <fcntl.h>//open()
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"

# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_INPUT "Invalid number of arguments.\n"
# define ERROR_PIPE "Pipe"
# define ERROR_CMD "Command not found\n"

typedef struct s_pipex
{
	int		outfile;
	int		infile;
	int		fd[2];
	pid_t	*pid;
	char	**path;
}	t_pipex;

char	**find_path(char **envp);
char	*get_cmd(t_pipex *pipex, char **argument);
void	child(t_pipex *pipex, char **argv, char **envp, int i);
void	piping(t_pipex *pipex, char **argv, int i);

void	free_stored_data(char **ptr);
void	false_arg(void);
void	close_and_wait(t_pipex *pipex, int *status);
void	free_and_exit(t_pipex *pipex, int exit_stat);
t_pipex	*pipe_init(char **envp);

#endif