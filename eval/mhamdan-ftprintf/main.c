#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(int c, char **v)
{
	if(c == 2)
	{
		printf("%d\n",ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
		printf("%d\n",printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	}
}
