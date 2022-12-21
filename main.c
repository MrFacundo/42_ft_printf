#include "ft_printf.h"
#include <stdio.h>

void main()
{
	// ft_printf("print char %c %s", 'c', "-followed by s string");
	printf("print int %d\n", 42);
	ft_printf("print int %d", 42);
}