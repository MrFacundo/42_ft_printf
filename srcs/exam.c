#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	ret = 0;

	if (!str)
		return ft_putstr("(null)");
	while (*str)
		ret += ft_putchar(*str++);
	return ret;
}

int	ft_putunbr(unsigned long long n, int base)
{
	int	ret = 0;
	char	*digits = "0123456789abcdef";
	if (n / base)
		ret += ft_putunbr(n / base, base);
	ret += ft_putchar(digits[n % base]);
	return ret;
}


int	ft_putnbr(long long n, int base, int uppercase)
{
	char	*digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	int	ret = 0;

	if (n < 0)
	{
		n = -n;
		ret += ft_putchar('-');
	}
	if (n / base)
		ret += ft_putnbr(n / base, base, uppercase);
	ret += ft_putchar(digits[n % base]);
	return ret;
}

int	ft_putptr(unsigned long long ptr)
{
	int	ret = 0;

	if (!ptr)
		return ft_putstr("(nil)");
	ret += ft_putstr("0x");
	ret += ft_putunbr(ptr, 16);
	return ret;
}


int	parse_specifier(char c, va_list args)
{
	int	ret = 0;

	if (c == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ret +=  ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		ret +=  ft_putnbr(va_arg(args, int), 10, 0);
	else if (c == 'u')
		ret +=  ft_putunbr(va_arg(args, long long), 10);
	else if (c == 'x')
		ret +=  ft_putnbr(va_arg(args, long long), 16, 0);
	else if (c == 'X')
		ret +=  ft_putnbr(va_arg(args, long long), 16, 1);
	else if (c == '%')
		ret +=  ft_putchar('%');
	return ret;
}


int	ft_printf(char *str, ...)
{
	va_list args;
	int	ret = 0;
	va_start(args, str);

	while (*str)
	{
		if (*str == '%' && ++str)
			ret += parse_specifier(*str, args);
		else
			ret += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return ret;
}
/* 

int	main()
{
	char	a = 'a';
	char	*b = "abc";
	int		c = -245649798;

	printf("printf:\n");
	int printf_value = printf("%c, %s, %d, %x, %X, %p, %X\n", a, b, c, c, c, &c, 160);
	printf("%d\n", printf_value);

	printf("ft_printf:\n");
	int ft_printf_value = printf("%c, %s, %d, %x, %X, %p, %X\n", a, b, c, c, c, &c, 160);
	printf("%d\n", ft_printf_value);

	ft_printf("the password is %X", (unsigned int)3735929054);

}


 */