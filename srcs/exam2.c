#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_putstr(char *str)
{
	int ret = 0;

	if (!str)
		return ft_putstr("(null)");
	while (*str)
		ret += ft_putchar(*str++);
	return ret;
}

int	ft_putnbr(long long n, int base, int uppercase)
{
	int ret = 0;
	char	*digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n < 0)
	{
		n = -n;
		if (base != 16)
			ret += ft_putchar('-');
	}
	if (n / base)
		ret += ft_putnbr(n / base, base, uppercase);
	ret += ft_putchar(digits[n % base]);
	return ret;
}

int	ft_putunbr(unsigned long long n, int base)
{
	int ret = 0;
	char	*digits = "0123456789abcdef";
	if (n / base)
		ret += ft_putunbr(n / base, base);
	ret += ft_putchar(digits[n % base]);
	return ret;
}

int ft_putptr(unsigned long long n)
{
	int ret = 0;
	if (!n)
		return ft_putstr("(nil)");
	ret += ft_putstr("0x");
	ret += ft_putunbr(n, 16);
	return ret;
}

int	parse_specifier(char c, va_list arg)
{
	int ret = 0;

	if (c == 'c')
		ret += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		ret += ft_putptr(va_arg(arg, unsigned long long));
	else if (c == 'd' || c == 'i')
		ret += ft_putnbr(va_arg(arg, int), 10, 0);
	else if (c == 'u')
		ret += ft_putunbr(va_arg(arg, unsigned long long), 10);
	else if (c == 'x')
		ret += ft_putnbr(va_arg(arg, long long), 16, 0);
	else if (c == 'X')
		ret += ft_putnbr(va_arg(arg, long long), 16, 1);
	else if (c == '%')
		ret += ft_putchar('%');
	return ret;
}

int	ft_printf(char *str, ...)
{
	int	ret = 0;
	va_list arg;

	va_start(arg, str);
	while (*str)
	{
		if (*str == '%' && ++str)
			ret += parse_specifier(*str, arg);	
		else
			ret += ft_putchar(*str);
		str++;
	}
	return ret;
}

int	main()
{
	char a = 'c';
	char *b = "abc";
	int	c = 5;
	int	d = -4604;

	printf("printf:\n");
	int printf_ret = printf("%c, %s, %p, %d, %u, %x, %X\n", a, b, &c, d, d, d, d);
	printf("%d\n", printf_ret);
	
	printf("ft_printf:\n");
	int ft_printf_ret = ft_printf("%c, %s, %p, %d, %u, %x, %X\n", a, b, &c, d, d, d, d);
	printf("%d\n", ft_printf_ret);
}