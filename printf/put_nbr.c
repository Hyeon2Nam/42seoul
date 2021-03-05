/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:46:09 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/03 22:22:57 by hyenam           ###   ########.fr       */
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

void put_pre(unsigned long long n, int len)
{
	int minus;

	minus = 0;
	if (option.neg_num)
	{
		ft_putchar_fd('-', 1);
		printf_cnt++;
		minus = 1;
	}
	option.width = option.pre - len;
	put_blank_zero(option.width - minus, 1);
	ft_putnbr_fd(n, 1);
}

void put_left_width(unsigned long long n, int len)
{
	int minus;
	int width;

	minus = 0;
	if (option.neg_num)
	{
		ft_putchar_fd('-', 1);
		printf_cnt++;
		minus = 1;
	}
	width = option.pre - len;
	put_blank_zero(width, 1);
	ft_putnbr_fd(n, 1);
	put_blank_zero(option.width - minus, 0);
}

void put_right_width(unsigned long long n, int len)
{
	if (option.neg_num)
	{
		option.width = option.width - option.pre - 1;
		put_blank_zero(option.width, 0);
		ft_putchar_fd('-', 1);
		printf_cnt++;
	}
	else
	{
		option.width = option.width - option.pre;
		put_blank_zero(option.width, 0);
	}
	option.width = option.pre - len;
	put_blank_zero(option.width, 1);
}

void set_width(unsigned long long n, int len)
{
	if (option.pre >= option.width)
		put_pre(n, len);
	else if (option.width != 0 && option.pre < option.width)
	{
		if (option.minus)
			put_left_width(n, len);
		else
			put_right_width(n, len);
	}
	else
		ft_putnbr_fd(n, 1);
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
	set_width(n, len);
}
