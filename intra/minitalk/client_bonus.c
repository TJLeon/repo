/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:51:11 by leotan            #+#    #+#             */
/*   Updated: 2024/09/16 16:21:07 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static pid_t	str_to_pid(char *str)
{
	pid_t	pid;
	int		i;

	pid = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		pid = (pid * 10) + (str[i++] - 48);
	if (str[i] != '\0' || pid < 1 || i < 1 || kill(pid, 0) != 0)
		exit(((void)write(STDERR_FILENO, "Error Bad PID\n", 14), 1));
	return (pid);
}

static void	msg_to_server(pid_t pid, char *msg)
{
	int	msg_index;
	int	bit_index;
	int	kill_err;

	msg_index = 0;
	bit_index = 7;
	kill_err = 0;
	while (msg[msg_index] != '\0')
	{
		while (bit_index >= 0)
		{
			if (((msg[msg_index] >> bit_index--) & 1) == 0)
				kill_err = kill(pid, SIGUSR1);
			else
				kill_err = kill(pid, SIGUSR2);
			if (kill_err != 0)
				exit(((void)write(STDERR_FILENO, "Server Not Found\n", 17), 1));
			pause();
		}
		bit_index = 7;
		msg_index++;
	}
	return ;
}

static void	sa_sig_handler(int signum)
{
	usleep(90);
	if (signum == SIGUSR1)
		write(STDOUT_FILENO, "Server Received A Bit\n", 22);
	return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_settings;

	if (argc != 3 || argv[1][0] == '\0')
		return (write(STDERR_FILENO, "Error Invalid Input\n", 20), 1);
	sigemptyset(&sa_settings.sa_flags);
	sigemptyset(&sa_settings.sa_mask);
	sa_settings.sa_handler = &sa_sig_handler;
	sigaction(SIGUSR1, &sa_settings, NULL);
	return (msg_to_server(str_to_pid(argv[1]), argv[2]), 0);
}
