/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:11:47 by facundo           #+#    #+#             */
/*   Updated: 2023/09/29 09:55:56 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	parse_specifier(char c, va_list args)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ret += ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		ret += ft_putnbr_base(va_arg(args, int), 10, 0);
	else if (c == 'u')
		ret += ft_putunbr_base(va_arg(args, long long), 10);
	else if (c == 'x')
		ret += ft_putnbr_base(va_arg(args, long long), 16, 0);
	else if (c == 'X')
		ret += ft_putnbr_base(va_arg(args, long long), 16, 1);
	else if (c == '%')
		ret += ft_putchar(c);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	args;

	ret = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && str++)
			ret += parse_specifier(*str++, args);
		else
			ret += ft_putchar(*str++);
	}
	va_end(args);
	return (ret);
}
