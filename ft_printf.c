/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:38 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/17 17:07:53 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
	return 1;
}


int parse_specifier(char *str, va_list args)
{
	int print_length;

	print_length = 0;

	if (*str == 'c')
		print_length += ft_printf_char(va_arg(args, int));
	return (print_length);
}

int ft_printf(const char *str, ...)
{
	int return_value;
	va_list args;

	return_value = 0;
	va_start(args, str);
	while (*str)
		if (*str == '%' && *++str)
		{
			return_value += parse_specifier((char *)str, args);
			str++;
		}
		else
		{
			return_value++;
			ft_putchar_fd(*str, 1);
			str++;
		}
	va_end(args);
	return return_value;
}
