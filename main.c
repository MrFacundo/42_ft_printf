#include "ft_printf.h"
#include <stdio.h>

void main()
{
	// ft_printf("print char %c %s", 'c', "-followed by s string");
	printf("print char %c\n", 'c');
	ft_printf("print char %c", 'c');
}