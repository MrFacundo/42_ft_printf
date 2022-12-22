/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:38 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/21 20:36:30 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int parse_specifier(char *str, va_list args)
{
	int print_length;

	print_length = 0;

	if (*str == 'c')
		print_length += ft_printf_char(va_arg(args, int));
	else if (*str == 's')
		print_length += ft_printf_str(va_arg(args, char *));
	else if (*str == 'p')
		print_length += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (*str == 'd' || *str == 'i')
		print_length += ft_printf_nbr(va_arg(args, int));
	else if (*str == 'u')
		print_length += ft_printf_unsigned(va_arg(args, unsigned int), 10, 0);
	else if (*str == 'x')
		print_length += ft_printf_unsigned(va_arg(args, unsigned int), 16, 0);
	else if (*str == 'X')
		print_length += ft_printf_unsigned(va_arg(args, unsigned int), 16, 1);
	else if (*str == '%')
		print_length += ft_printf_char(*++str);
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
