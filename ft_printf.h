/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:39:39 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/15 22:59:16 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

typedef struct specifier
{
	int 		len;
	va_list		args;

}	specifier;


/* ft_printf.c */
int	ft_printf(const char *str, ...);

#endif