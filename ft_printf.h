/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:39:39 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/27 15:20:11 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

/* ft_printf.c */
int		t_printf(const char *str, ...);
int		parse_specifier(char *str, va_list args);

/* ft_printf_functions.c */
int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_printf_nbr(int n);
int		ft_printf_unsigned(unsigned int n, int base, int uppercase);
int		ft_printf_ptr(unsigned long long ptr);

/* ft_printf_utils.c */
int		ft_num_length(int n, int base);
int		ft_unsigned_num_length(unsigned long long n, int base);
void	ft_putfnbr_base_fd(long long n, int base, int uppercase, int fd);
void	ft_putunbr_base_fd(unsigned long long n, int base, int fd);

#endif
