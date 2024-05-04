/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:36:18 by leotan            #+#    #+#             */
/*   Updated: 2024/05/04 14:04:03 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
{
	int	i;
	int	n;
	int	r;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	n = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			n = -1;
		i++;
	}
	r = 0;
	while (s[i] >= '0' && s[i] <= '9')
		r = (r * 10) + (s[i++] - '0');
	return (r * n);
}
