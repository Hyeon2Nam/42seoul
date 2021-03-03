/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:46:09 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/03 21:19:08 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_len(unsigned long long value, int base)
{
	int res;

	res = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		res++;
	}
	return (res);
}

unsigned long long ft_change_unsigned_base(unsigned long long n, int cl)
{
	int r;

	r = n % option.base;
	n /= option.base;
	if (n > 0)
		ft_change_unsigned_base(n, cl);
	if (r < 10)
		ft_putnbr_fd(r, 1);
	else
		ft_putchar_fd(r - 10 + (cl == 1 ? 'A' : 'a'), 1);
}

void put_width_neg_num(unsigned long long n, int len)
{
	if (option.width <= option.pre)
	{
		option.width = option.pre - len - 1;
		ft_putchar_fd('-', 1);
		printf_cnt++;
		put_blank_zero(option.width, 1);
	}
	if (option.width > 0 && option.width > option.pre)
	{
		option.width = option.width - option.pre - 1;
		put_blank_zero(option.width, 0);
		ft_putchar_fd('-', 1);
		printf_cnt++;
		option.width = option.pre - len;
		put_blank_zero(option.width, 1);
	}
}

void put_width(unsigned long long n, int len)
{
	if (option.width <= option.pre)
	{
		option.width = option.pre - len;
		put_blank_zero(option.width, 1);
	}
	if (option.width > 0 && option.width > option.pre)
	{
		option.width = option.width - option.pre - 1;
		put_blank_zero(option.width, 0);
		option.width = option.pre - len;
		put_blank_zero(option.width, 1);
	}
}

void put_nbr(unsigned long long n)
{
	int len;
	int cl;

	if (option.type == 'x' || option.type == 'X' || option.type == 'p')
		option.base = 16;
	if (n < 0)
	{
		option.neg_num = 1;
		n *= -1;
	}
	if (option.type == 'X')
		cl = 1;
	else
		cl = 0;
	n = ft_change_unsigned_base(n, cl);
	len = ft_len(n, option.base);
	if (option.minus)
	{
		if (option.neg_num)
			put_blank_neg_num(n, len);
		else
			set_width(n, len);
	}
	else
	{
		if (option.neg_num)
			put_blank_neg_num(n, len);
		else
			set_width(n, len);
	}
}
