/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:17:59 by hsim              #+#    #+#             */
/*   Updated: 2023/10/01 16:28:21 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;	
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	j = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size <= destlen)
		return (size + srclen);
	while (dest[i] != '\0')
		i++;
	while ((destlen + j) < (size - 1) && src[j] != '\0')
		dest[i++] = src[j++];
	if (size != 0)
		dest[i] = '\0';
	return (destlen + srclen);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	unsigned int	y;
	char			*src;
	unsigned int	a;

	a = 8;
	char dest[7] = "hello";
	src = "world";
	y = ft_strlcat(dest, src, a);
	printf("Count: %d\n", y);
	printf("%s\n", dest);
	return (0);
}*/


/*
(tested in strlcat)
if size <= strlen(dest), sizeof(dest) > strlen(dest+src) or < strlen(dest+src)
return size + strlen(src), excl NUL terminator
return (dest)

if size > strlen(dest)-
if size > sizeof(dest), sizeof(dest) < strlen(dest+src) or > strlen(dest+src)
append src to dest, if dest is full, dest dont NUL terminate
which will result in Abort trap: 6

if size <= sizeof(dest), sizeof(dest) > strlen(dest+src) or < strlen(dest+src)
append src to dest until size - 1
return (strlen(dest+src))

if size = 0
donot cat, return strlen(src)
-
(man 1998)
takes full size of buffer
NULL terminate result (as long as size is > 0 or free byte in dst)
NUL should be included when declare size
src & dst must be null terminated to work in strlcat

appends src to end of dst, at most, size - strlen(dst) - 1 byte 
(NUL terminates result)

returns the total length of string they try to create,
strlen(dst) + strlen(src)

if size < length of string
length of string = size, will not be NUL terminated in this case
*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
	//char dst1[7] = "hello";
	char dst2[7] = "hello";
	if (argc == 3)
	{
		//printf("%u\n", ft_strlcat(dst1, argv[1], atoi(argv[2])));
		//printf("%s\n", dst1);
		printf("%lu\n", strlcat(dst2, argv[1], atoi(argv[2])));
		printf("%s\n", dst2);
	}
	return (0);
}