/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:39:12 by hetan             #+#    #+#             */
/*   Updated: 2023/12/24 04:43:23 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_stored_data(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	false_arg(void)
{
	errno = EINVAL;
	perror(NULL);
	exit(EINVAL);
}

void	close_and_wait(t_pipex *pipex, int *status)
{
	close(pipex -> fd[0]);
	close(pipex -> fd[1]);
	waitpid(pipex -> pid[0], status, 0);
	waitpid(pipex -> pid[1], status, 0);
}

void	free_and_exit(t_pipex *pipex, int exit_status)
{
	free_stored_data(pipex -> path);
	free(pipex -> pid);
	free(pipex);
	exit (exit_status);
}

t_pipex	*pipe_init(char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(EXIT_FAILURE);
	pipex -> pid = malloc(2 * sizeof(pid_t));
	if (!pipex -> pid)
	{
		free(pipex);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipex -> fd) < 0)
	{
		free(pipex -> pid);
		free(pipex);
		exit (EXIT_FAILURE);
	}
	pipex -> path = find_path(envp);
	return (pipex);
}
