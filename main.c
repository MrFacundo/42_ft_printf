#include "ft_printf.h"
#include <stdio.h>

void main()
{
	int x = 99;
	int *pt1;

	pt1 = &x;

	printf("print string %%\n");
	ft_printf("print string %%");
}