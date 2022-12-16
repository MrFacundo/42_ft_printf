/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:38 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/15 23:08:02 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void ft_printf_char(specifier *fmt)
{
	const char c = va_arg(fmt->args, int);

	ft_putchar_fd(c, 1);
}

// static void initialize_specifier(specifier *fmt)
// {
// 	// fmt->len = 0;
// }

// static char *parse_flags(char *str, specifier *fmt)
// {
// 	return str;
// }

static char *parse_format_specifier(char *str, specifier *fmt)
{
	while (*str && !ft_strchr("cspdiuxX%", *str))
		// parse_flags(str, fmt);
	if (*str == 'c')
		ft_printf_char(fmt);
	return (++str);
}

int ft_printf(const char *str, ...)
{
	int return_value;
	specifier fmt;

	return_value = 0;
	va_start(fmt.args, str);
	while (*str)
		if (*str == '%' && *str++)
		{
			// *str++;
			str = parse_format_specifier((char *)str, &fmt);
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
