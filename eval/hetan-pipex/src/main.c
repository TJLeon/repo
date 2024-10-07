/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:48 by hetan             #+#    #+#             */
/*   Updated: 2023/12/24 04:46:32 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	int		i;
	char	**path;
	char	*temp;

	i = -1;
	while (envp && envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			i = -1;
			while (path[++i])
			{
				temp = path[i];
				path[i] = ft_strjoin(path[i], "/");
				free(temp);
			}
			return (path);
		}
	}
	path = ft_split("/usr/bin/", ' ');
	return (path);
}

char	*get_cmd(t_pipex *pipex, char **argument)
{
	int		i;
	char	*string;

	i = 0;
	if (!access(argument[0], F_OK))
	{
		if (!access(argument[0], X_OK))
			return (argument[0]);
		else
			exit(126);
	}
	while (pipex -> path[i])
	{
		string = ft_strjoin(pipex -> path[i], argument[0]);
		if (!access(string, F_OK))
		{
			if (!access(string, X_OK))
				return (string);
			else
				exit(126);
		}
		i++;
	}
	errno = ENOENT;
	return (NULL);
}

void	child(t_pipex *pipex, char **argv, char **envp, int i)
{
	char	**command;

	piping(pipex, argv, i);
	command = ft_split(argv[i + 2], ' ');
	if (get_cmd(pipex, command) == NULL)
	{
		dup2(2, 1);
		ft_printf("%s: %s: command not found\n", argv[0] + 2, command[0]);
		exit(127);
	}
	execve(get_cmd(pipex, command), command, envp);
	free_and_exit(pipex, EXIT_FAILURE);
}

void	piping(t_pipex *pipex, char **argv, int i)
{
	if (i == 0)
	{
		pipex -> outfile = open(argv[1], O_RDONLY);
		if (pipex -> outfile < 0)
			perror("pipex: input");
		if (dup2(pipex -> outfile, STDIN_FILENO) < 0)
			free_and_exit(pipex, EXIT_FAILURE);
		close(pipex -> outfile);
		if (dup2(pipex -> fd[1], STDOUT_FILENO) < 0)
			free_and_exit(pipex, EXIT_FAILURE);
	}
	else
	{
		pipex -> infile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (pipex -> infile < 0)
			perror("pipex: output");
		if (dup2(pipex -> infile, STDOUT_FILENO) < 0)
			free_and_exit(pipex, EXIT_FAILURE);
		close(pipex -> infile);
		if (dup2(pipex -> fd[0], STDIN_FILENO) < 0)
			free_and_exit(pipex, EXIT_FAILURE);
	}
	close(pipex -> fd[0]);
	close(pipex -> fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;
	int		status;

	if (argc != 5)
		false_arg();
	i = -1;
	pipex = pipe_init(envp);
	while (++i < 2)
	{
		pipex -> pid[i] = fork();
		if (pipex -> pid[i] < 0)
			free_and_exit(pipex, EXIT_FAILURE);
		if (!pipex -> pid[i])
			child(pipex, argv, envp, i);
	}
	close_and_wait(pipex, &status);
	if ((status & 0x7f) == 0)
		free_and_exit(pipex, status >> 8);
	free_and_exit(pipex, status);
}
