/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:39:39 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/21 20:55:21 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

/* ft_printf.c */
int	ft_printf(const char *str, ...);
int parse_specifier(char *str, va_list args);

int ft_printf_char(char c);
int	ft_printf_str(char *str);
int	ft_printnbr(int n);
int ft_print_unsigned(unsigned int n);
int	ft_numlen(int n, int base);
int		ft_unumlen(unsigned long long n, int base);
void	ft_putfnbr_base_fd(long long n, int base, int fd);


#endif