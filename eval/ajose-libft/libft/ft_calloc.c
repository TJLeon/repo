/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose <ajose@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:30:29 by ajose             #+#    #+#             */
/*   Updated: 2024/07/21 23:32:55 by ajose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t t)
{
	void	*ptr;

	if (t != 0 && n > UINT32_MAX / t)
		return (NULL);
	ptr = malloc(n * t);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, n * t);
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int    main(void)
{
    char    *str;
    char    *str1;

    str = (char *)calloc((size_t)INT_MIN, sizeof((size_t)INT_MIN));
    if (strcmp(str, "") == 0)
        printf("calloc: str has been zeroed out.\n");
    else
        printf("calloc: str has not been zeroed out.\n");
    free(str);

    str1 = (char *)ft_calloc(INT_MIN, sizeof(INT_MIN));
    if (strcmp(str1, "") == 0)
        printf("ft_calloc: has been zeroed out.\n");
    else
        printf("ft_calloc: has not been zeroed out.\n");
    free(str1);

    return (0);
}
*/
