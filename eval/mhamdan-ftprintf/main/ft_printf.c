/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:52:34 by mhamdan           #+#    #+#             */
/*   Updated: 2023/12/24 02:38:27 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	search_convertion(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char((va_arg(args, int))));
	else if (c == 's')
		return (ft_print_str((va_arg(args, char *))));
	else if (c == 'p')
		return (ft_print_ptr(((uintptr_t)va_arg(args, void *))));
	else if (c == 'd' || c == 'i')
		return (ft_print_num((va_arg(args, int))));
	else if (c == 'u')
		return (ft_print_unum((va_arg(args, unsigned int))));
	else if (c == 'x')
		return (ft_print_low_hex((va_arg(args, unsigned int))));
	else if (c == 'X')
		return (ft_print_upp_hex((va_arg(args, unsigned int))));
	else if (c == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	va_start(args, format);
	length = 0;
	i = -1;
	if (format)
	{
		while (format[++i])
		{
			if (format[i] != '%')
				length += ft_print_char(format[i]);
			else
				length += search_convertion(format[++i], args);
		}
	}
	va_end(args);
	return (length);
}
