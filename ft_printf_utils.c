#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
	return 1;
}

int ft_printf_str(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int ft_printnbr(int n)
{
	int len;

	len = ft_numlen(n, 10);
	ft_putfnbr_base_fd(n, 10, 1);
	return (len);
}

int ft_print_unsigned(unsigned int n)
{
	int len;

	len = ft_unumlen(n, 10);

	ft_putfnbr_base_fd(n, 10, 1);

	return (len);
}

int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

int ft_unumlen(unsigned long long n, int base)
{
	if (!(n / base))
		return (1);
	return (1 + ft_unumlen(n / base, base));
}

void	ft_putfnbr_base_fd(long long n, int base, int fd)
{
	int			sign;
	const char	*digits = "0123456789abcdef";

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	if (n / base)
		ft_putfnbr_base_fd(n / base * sign, base, fd);
	ft_putchar_fd(digits[n % base * sign], fd);
}