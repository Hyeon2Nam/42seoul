/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:39:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/14 14:11:58 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void put_blank_zero(int width, int zero)
{
	int i;

	i = 0;
	while (++i < width)
	{
		if (zero == 1)
			printf_cnt += ft_putchar_fd('0');
		else
			printf_cnt += ft_putchar_fd(' ');
	}
}

void put_char(int c)
{
	if (option.minus == 1)
		printf_cnt += ft_putchar_fd(c);
	put_blank_zero(option.width, option.zero);
	if (option.minus == 0)
		printf_cnt += ft_putchar_fd(c);
}
