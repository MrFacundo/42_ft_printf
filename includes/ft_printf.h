/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:39:39 by ftroiter          #+#    #+#             */
/*   Updated: 2023/09/27 14:16:14 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* ft_printf.c */
int	ft_printf(const char *str, ...);

/* utils.c */
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putunbr_base(unsigned long long n, int base);
int	ft_putnbr_base(long long n, int base, int uppercase);
int	ft_putptr(unsigned long long ptr);

#endif
