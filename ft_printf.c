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

int	ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);

	while (*str)
		if (*str != '%' && str++)
			ft_putchar_fd(*str, 1);
		else
		{
			str++;
			switch (*str)
			{
			case 'd':
				int i = va_arg(args, int);
				ft_putnbr_fd(i, 1);
				break;
			case 'c':
				char c = va_arg(args, char);
				ft_putchar_fd(c, 1);
				break;
			default:
				break;
			}
		}	
	return 0;
}
