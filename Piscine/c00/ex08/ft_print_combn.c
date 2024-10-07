/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 05:46:09 by leotan            #+#    #+#             */
/*   Updated: 2023/09/19 14:51:24 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_putstr(char *s, int p)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	if (p == 1)
		write(1, ", ", 2);
}

void	ft_change(char *s, int n)
{
	int	i;
	int	j;

	if (s[n - 1] != '9')
	{
		s[n - 1] += 1;
		return ;
	}
	i = 0;
	while (s[i + 1] != '\0')
	{
		j = i;
		if ((s[i] != (58 - n + i)) && (s[i + 1] == (59 - n + i)))
		{
			s[i] += 1;
			while ((s[j] != (60 - n)) && (s[j + 1] != '\0'))
			{
				s[j + 1] = (s[j] + 1);
				j++;
			}
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	s[10];
	int		i;

	i = 0;
	while (i < n)
	{
		s[i] = (i + '0');
		i++;
	}
	s[i] = '\0';
	while (s[0] != (58 - n))
	{
		ft_putstr(s, 1);
		ft_change(s, n);
	}
	ft_putstr(s, 0);
}

int	main(void)
{
	ft_print_combn(5);
	return (0);
}
