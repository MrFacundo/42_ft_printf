#include <limits.h>
#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
	return 1;
}

int ft_printf_str(char *str)
{
	int len;

	len = 0;
	if (!str)
	{
		str = "(null)";
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	while (*str)
	{
		len += ft_printf_char(*str);
		str++;
	}
	return (len);
}

int ft_printf_nbr(int n)
{
	int len;

	len = ft_num_length(n, 10);
	ft_putfnbr_base_fd(n, 10, 0, 1);
	return (len);
}

int ft_printf_unsigned(unsigned int n, int base, int uppercase)
{
	int len;

	len = ft_unsigned_num_length(n, base);
	ft_putfnbr_base_fd(n, base, uppercase, 1);
	return (len);
}

int ft_printf_ptr(unsigned long long ptr)
{
	const long long n = ptr + ULONG_MAX + 1;
	const int len = ft_unsigned_num_length(n, 16) + 2;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
	ft_putstr_fd("0x", 1);
	ft_putunbr_base_fd(n, 16, 1);

	return (len);
}