#include "ft_printf.h"
#include "libft/libft.h"

int	ft_num_length(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

int	ft_unsigned_num_length(unsigned long long n, int base)
{
	if (!(n / base))
		return (1);
	return (1 + ft_unsigned_num_length(n / base, base));
}

void	ft_putfnbr_base_fd(long long n, int base, int uppercase, int fd)
{
	int		sign;
	char	*digits;

	digits = "0123456789abcdef";
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	if (uppercase)
		digits = "0123456789ABCDEF";
	if (n / base)
		ft_putfnbr_base_fd(n / base * sign, base, uppercase, fd);
	ft_putchar_fd(digits[n % base * sign], fd);
}

void	ft_putunbr_base_fd(unsigned long long n, int base, int fd)
{
	const char	*digits = "0123456789abcdef";

	if (n / base)
		ft_putunbr_base_fd(n / base, base, fd);
	ft_putchar_fd(digits[n % base], fd);
}
