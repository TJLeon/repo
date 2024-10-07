/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:41:29 by leotan            #+#    #+#             */
/*   Updated: 2024/09/15 01:15:20 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void	putpid(pid_t pid)
{
	if (pid > 9)
		putpid(pid / 10);
	write(STDOUT_FILENO, &"0123456789"[pid % 10], 1);
	return ;
}

static void	sa_sig_handler(int signum, siginfo_t *info, void *content)
{
	static char	c = 0;
	static int	bit_index = 1;

	(void)content;
	if (signum == SIGUSR1)
		c = (c << 1);
	else if (signum == SIGUSR2)
		c = (c << 1) | 1;
	if (bit_index++ == 8)
	{
		bit_index = 1;
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	usleep(90);
	if (kill(info->si_pid, SIGUSR1) != 0)
		exit(((void)write(STDERR_FILENO, "Client Not Found\n", 17), 1));
	return ;
}

int	main(void)
{
	struct sigaction	sa_settings;

	write(STDOUT_FILENO, "Server PID = ", 14);
	putpid(getpid());
	write(STDOUT_FILENO, "\n", 1);
	sigemptyset(&sa_settings.sa_mask);
	sa_settings.sa_flags = SA_SIGINFO;
	sa_settings.sa_sigaction = &sa_sig_handler;
	sigaction(SIGUSR1, &sa_settings, NULL);
	sigaction(SIGUSR2, &sa_settings, NULL);
	while (1)
		pause();
	return (0);
}
