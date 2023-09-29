/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:13:13 by facundo           #+#    #+#             */
/*   Updated: 2023/09/29 11:54:53 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	char			*test = 0;
	int				a = -5;
	unsigned int	b = -5;
	int				c = -30;
	int				d = 0;
	int				e = -80000000;

	printf("printf: \n");
	int	printf_ret_value = printf("%s, %p, %d, %u, %x, %X, %d\n", test, &a, a,
			b, c, c, e);
	printf("ret value: %d\n", printf_ret_value);

	printf("ft_printf: \n");
	int	ft_printf_ret_value = ft_printf("%s, %p, %d, %u, %x, %X, %d\n", test,
			&a, a, b, c, c, e);
	printf("ret value: %d\n", ft_printf_ret_value);
}