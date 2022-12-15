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
	int return_value;
	fmt_specifier fmt;

	return_value = 0;
	va_start(fmt.args, str);
	while (*str)
		if (*str == '%')
		{
			return 0; //parse_args
		}
		else
		{
			return_value++;
			ft_putchar_fd(*str++, 1);
		}
	va_end(fmt.args);
	return_value += fmt.len;
	return return_value;
}
