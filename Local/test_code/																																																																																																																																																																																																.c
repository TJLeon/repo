/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   																																											        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/01/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2024/10/31 18:27:28 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <mlx.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

// int main()
// {
	// printf("\n");
	// write(1,"\n",1);
// }

// int main()
// {
// 	char *p = calloc(3,1);
// 	p[0] = '4';
// 	p[1] = '2';
// 	printf("%p\n%p\n%p\n",&p[0],&p[1],&p[2]);
// }

// void ft_ft()
// {
// 	ft_ft();
// }

// int main()
// {
// 	ft_ft();
// }

// int main()
// {
// 	printf("%ld\n",1L);
// }

// void ft_test(const char *p1)
// {
// 	(void)p1;
// }

// int main()
// {
// 	char *p1=calloc(2,1);
// 	p1[0]='7';
// 	ft_test(p1);
// }

// int main(int c, char **v, char **ev)
// {
// 	for(int i = 0; ev[i]; i++)
// 		printf("%s\n",ev[i]);
// }

// void ft_sighandler(int sig)
// {
// 	// printf("CTRL-C\n");
// }

// void ft_test()
// {
// 	signal(SIGINT, &ft_sighandler);
// }

// int main()
// {
// 	char	*p;
// 	ft_test();
// 	while (1)
// 	{
// 		p = readline("minishell$ ");
// 		if (p == NULL)
// 		{
// 			printf("\n");
// 			exit(0);
// 		}
// 		if (p[0] != '\0')
// 			printf("%s\n",p);
// 		free(p);
// 	}
// }

// int main()
// {
// 	char *p;
// 	while(1)
// 	{
// 	p = readline("Home $ ");
// 	int n = strlen(p);
// 	printf("%d\n",n);
// 	}
// }

// static void	ft_put_positive_number(size_t n)
// {
// 	if (n > 9)
// 		ft_put_positive_number(n / 10);
// 	write(1, &"0123456789"[n % 10], 1);
// }

// int	main(void)
// {
	// ft_put_positive_number(0);
// 	void *mlx = mlx_init();
// 	void *mlx_win = mlx_new_window(mlx,5*64,3*64,"");
// 	mlx_loop(mlx);
// }

// gcc -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit a.c

// ESC 53
// W 13
// A 0
// S 1
// D 2

// int main()
// {
// 	char *p = "AAAAAAAA";
// 	int i = 0;
// 	while (p[i])
// 		if(p[i++] == 'A')
// 			printf("%c\n",'0');
// }

// int main()
// {
// 	char *a = "Leon";
// 	int i = 3;
// 	if (a[i + 1] == '\0' && a[i++] == 'n')
// 		printf("valid");
// }

// void ft_ft_ft()
// {
// 	char *a = calloc(64, 1);
// 	a[0] = 0;
// 	a = NULL;
// 	// system("leaks a.out");
// 	exit(1);
// }

// void ft_ft()
// {
// 	char *a = calloc(32, 1);
// 	a[0] = 0;
// 	a = NULL;
// 	ft_ft_ft();
// 	// system("leaks a.out");
// 	exit(1);
// }

// int main()
// {
// 	ft_ft();
// }

// int main()
// {
// 	exit(2);
// }

// int main()
// {
// 	read(-1, NULL, 0);
// 	perror(NULL);
// }

// int main()
// {
// 	exit(write(STDERR_FILENO, "Error\nInvalid Map Character", 64));
// }

// int main()
// {
// 	int i = 0;
// 	int x = 0;
// 	while("abc"[i] != '\0')
// 	{
// 		x = 0;
// 		while("01abc"[x] != '\0' && "abc"[i] != "01abc"[x])
// 			x++;
// 		printf("%c\n","01abc"[x]);
// 		i++;
// 	}
// }

// int main()
// {
// 	char *p = calloc(64,1);
// 	int fd = open("a.c",O_RDONLY);
// 	fd = -1;
// 	system("leaks a.out");
// }

// int main()
// {
	// char test[(SIZE_MAX / 8)];
	// if(test[0])
	// ;
	// ssize_t a=0;
	// size_t b=0;
	// if(a == b)
	// 	exit(0);
	// return(1);
// }

// int main()
// {
// 	int x = 0;
// 	int i = 0;
// 	char *p = "Leon";
// 	char b[5];
// 	while (p[i])
// 		b[x++] = p[i++];
// }

// int main(void)
// {
// 	int len;
// 	len = strlen(NULL);
// }

// int main(int ac, char **av)
// {
// 	printf("%s\n",av[1]);
// 	for(int a = 0; av[1][a]; a++)
// 		printf("%d\n",(unsigned char)av[1][a]);
// }

// int main(void)
// {
// 	char c = 240;
// 	write(1,&c,1);
// 	c = 159;
// 	write(1,&c,1);
// 	c = 140;
// 	write(1,&c,1);
// 	c = 141;
// 	write(1,&c,1);
// }

// int main()
// {
// 	unsigned char c=0;
// 	for(int n=0;n<7;n++)
// 		c=(c<<1)|1;
// 	printf("%d\n",c);
// }

// int main(int c, char **v)
// {
// 	if (v[1][0] == '\0')
// 		return (0);
// }

// int main()
// {
// 	int x;
// 	int n;
// 	x = (unsigned int)&n;
// 	n = (unsigned int)&x;
// 	while (1)
// 	{
// 		x = (unsigned int)(n * x) * (x * n) - (-n);
// 		n = x;
// 		printf("%d\n",n);
// 	}
// }

// 1 0
// 1 1
// 2 1
// 3 1

// 4 67 3 87 23

// 4 3 23 67 87

// pb
// ra
// ra
// pb
// pb
// pa
// pa
// pa
// pb
// pb
// ra
// ra
// pb
// pa
// pa
// pa
// pb
// ra
// pb
// pb
// pa
// pa
// pa

// int main()
// {
// 	char *p;
// 	for(unsigned long n = 34359738359; n > 0; n += (34359738359/2))
// 	{
// 		p = calloc(n,1);
// 		memset(p,'A',n - 1);
// 		free(p);
// 		printf("%lu\n",n);
// 	}
// }

// int main(int c, char **v)
// {
// 	printf("%d\n",atoi(v[1])%2);
// }

// char *ft_ft_ft()
// {
// 	return (calloc(2,1));
// }

// void ft_ft(char *p)
// {
// 	if (p[0] == 0)
// 		p[0] = '0';
// 	printf("%s\n",p);
// }

// int main()
// {
// 	ft_ft(ft_ft_ft());
// }

// char *ft_ft()
// {
// 	char *p=calloc(128,1);
// 	exit(0);
// }

// int main()
// {
// 	ft_ft();
// }

// void ft_ft(void **ptr)
// {
// 	int	i;

// 	if (ptr == NULL)
// 		return ;
// 	i = -1;
// 	while (ptr[++i] != NULL)
// 		free(ptr[i]);
// 	free(ptr);
// 	return ;
// }

// int main()
// {
// 	int n=-1;
// 	int x=0;
// 	char **str;
// 	str = calloc(4,sizeof(char*));
// 	for(int i=0;i<3;i++)
// 		str[i]=calloc(5,1);
// 	while(str[++n])
// 	{
// 		x=0;
// 		while(x<4)
// 			str[n][x++] = '0';
// 	}
// 	n=-1;
// 	x=0;
// 	int **tab;
// 	tab = calloc(4,sizeof(int*));
// 	for(int i=0;i<3;i++)
// 		tab[i]=calloc(1,sizeof(int));
// 	while(tab[++n])
// 		*(tab[n])=2147483647;
// 	ft_ft((void**)tab);
// 	ft_ft((void**)str);
// }

// int main()
// {
// 	int n = (write(1,"0123456789\n",11),1);
// 	printf("%d\n",n);
// }

// unsigned long long ft_ft()
// {
// 	return (42);
// }

// int main()
// {
// 	unsigned long long *p = malloc(ft_ft() * sizeof(unsigned long long));
// 	(void)p;
// }

// 4 3 2 1

// sa 3421 rra 1342 rra 2134 sa 1234

// sa 3421 ra 4213 ra 2134 sa 1234

// sa 3421 ra 4213 sa 2413 rra 3241 sa rra

// sa 3421 ra 4213 sa 2413 ra 4132 

// 1 2 4 3 5

// pb pb sa pa pa

// void ft_ft(int *p2)
// {
//     p2 = malloc(1);
// }

// int main()
// {
//     int *p1 = NULL;
//     ft_ft(p1);
//     printf("%p\n",p1);
// }

// int ft_ft()
// {
//     return (write(2,"Error\n",6));
// }

// int main()
// {
//     exit((NULL, ft_ft()));
// }

// 1 2 3

//y2 1 3 swap,  1 2 3

//y3 2 1 swap,  2 3 1
// 2 3 1 rev,   1 2 3

//y1 3 2 swap,  3 1 2
//y3 1 2 rot,   1 2 3

// char **ft_two()
// {
//     char **p = calloc(4,sizeof(char*));
//     int i = -1;
//     while(++i < 3)
//     p[i] = malloc(1);
//     p[i] = NULL;
//     return (p);
// }

// void ft_one(char **p)
// {
//     int i = -1;
//     while(p[++i] != NULL)
//     free(p[i]);
//     free(p);
// }

// int main()
// {
//     ft_one(ft_two());
// }

// void print_int128(__int128 value) {
//     if (value < 0) {
//         putchar('-');
//         value = -value;
//     }
//     if (value > 9) {
//         print_int128(value / 10);
//     }
//     putchar((value % 10) + '0');
// }

// int main() {
//     for (__int128 a = 0; a < 1; a--) {
//         print_int128(a);
//         putchar('\n');
//     }
//     return 0;
// }
