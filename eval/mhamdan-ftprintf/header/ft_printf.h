/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:51:43 by mhamdan           #+#    #+#             */
/*   Updated: 2023/12/24 02:39:07 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h> // va_list, va_start, va_arg and va_end
# include <stdint.h> // uintmax_t
# include <stdio.h>  // printf
# include <stdlib.h>
# include <unistd.h>

# if defined(__linux__)
#  define PTR0 "(nil)"
# else
#  define PTR0 "0x0"
# endif

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ptr_len(uintptr_t num);
void	putptr(uintptr_t num);
int		ft_print_ptr(uintptr_t ptr);
int		ft_print_num(int n);
int		num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unum(unsigned int n);
int		convert_to_hex(unsigned int num, int alph);
int		ft_print_low_hex(unsigned int num);
int		ft_print_upp_hex(unsigned int num);
int		ft_print_percent(void);

#endif
