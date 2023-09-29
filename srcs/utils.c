/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:13:44 by facundo           #+#    #+#             */
/*   Updated: 2023/09/29 11:34:50 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	ret;

	ret = 0;
	if (!str)
	{
		ret += ft_putstr("(null)");
		return (ret);
	}
	while (*str)
		ret += ft_putchar(*str++);
	return (ret);
}

int	ft_putunbr_base(unsigned long long n, int base)
{
	char	*digits;
	int		ret;

	digits = "0123456789abcdef";
	ret = 0;
	if (n / base)
		ret += ft_putunbr_base(n / base, base);
	ret += ft_putchar(digits[n % base]);
	return (ret);
}

int	ft_putnbr_base(long long n, int base, int uppercase)
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
	int	ret;

	ret = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	ret += ft_putstr("0x");
	ret += ft_putunbr_base(ptr, 16);
	return (ret);
}
