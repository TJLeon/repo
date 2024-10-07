/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:22:47 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/02 17:35:04 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)b;
	while (i < len)
		str[i++] = c;
	return (b);
}
//void * need to typecast to other data type to retrieve data stored inside it
/*
int	main(void)
{
    char str1[] = "Hello, World!";
    printf("Original String: %s\n", str1);
    ft_memset(str1, 'X', 5);
    printf("After ft_memset: %s\n", str1);

    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("Original Numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    ft_memset(numbers, 0, size * sizeof(int));
    printf("After ft_memset: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    char buffer[10];
    ft_memset(buffer, 'Z', 10);
    printf("Buffer after ft_memset: %s\n", buffer);

    return (0);
}
*/
