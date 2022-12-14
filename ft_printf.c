/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:38 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/12 23:30:08 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);

	while (*str)
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
		else
		{
			str++;
			switch (*str)
			{
			case 'd':
				ft_putnbr_fd(va_arg(args, int), 1);
				break;
			case 'c':
				ft_putchar_fd(va_arg(args, int), 1);
				break;
			case 's':
				ft_putstr_fd(va_arg(args, char *), 1);
				break;
			default:
				break;
			}
			str++;
		}
	va_end(args);
	return 0;
}
