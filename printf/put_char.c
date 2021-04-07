/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:39:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/07 12:23:21 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void put_blank_zero(int width, int zero)
{
	int i;
	// int result;

	i = 0;
	// result = 0;
	while (++i < width)
	{
		if (zero == 1)
			result += ft_putchar_fd('0');
		else
			result += ft_putchar_fd(' ');
	}
	// return (result);
}

void put_char(int c, t_option *option)
{
	// int result;

	// result = 0;
	if (option->minus == 1)
		result += ft_putchar_fd(c);
	put_blank_zero(option->width, option->zero);
	// result += put_blank_zero(option->width, option->zero);
	if (option->minus == 0)
		result += ft_putchar_fd(c);
	// return (result);
}
