// #include"get_next_line.h"
#include<unistd.h>
#include<stdlib.h>
#include<strings.h>
int main()
{
	char *p=calloc(4294967295,1);
	memset(p,'0',4294967294);
	while (1)
	;
	// get_next_line(0);
}
