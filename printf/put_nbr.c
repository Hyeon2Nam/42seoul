/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:46:09 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/14 21:36:10 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_len(unsigned long long value, int base)
{
	int res;

	res = 0;
	if (value == 0 && option.pre != 0)
		return (1);
	while (value)
	{
		value /= base;
		res++;
	}
	return (res);
}

void ft_change_base(unsigned long long n, int cl, char **num)
{
	int r;
	int len;
	int i;

	i = 1;
	len = ft_len(n, option.base);
	*num = (char *)malloc(sizeof(char) * (len + 1));
	(*num)[len] = 0;
	while (n > 0)
	{
		r = n % option.base;
		n /= option.base;
		if (r < 10)
			(*num)[len - i] = r;
		else
			(*num)[len - i] = r - 10 + (cl == 1 ? 'A' : 'a');
		(*num)[len - i] += '0';
		i++;
	}
}

void put_pre(char *n, int len)
{
	int minus;

	minus = 0;
	if (option.neg_num)
	{
		ft_putchar_fd('-');
		printf_cnt++;
		minus = 1;
	}
	option.width = option.pre - len;
	put_blank_zero(option.width - minus, 1);
	printf_cnt += ft_putstr_fd(n);
}

void put_left_width(char *n, int len)
{
	int minus;
	int width;

	minus = 0;
	if (option.neg_num)
	{
		ft_putchar_fd('-');
		printf_cnt++;
		minus = 1;
	}
	width = option.pre - len;
	put_blank_zero(width, 1);
	printf_cnt += ft_putstr_fd(n);
	put_blank_zero(option.width - minus, 0);
}

void put_right_width(char *n, int len)
{
	if (option.neg_num)
	{
		option.width = option.width - option.pre - 1;
		put_blank_zero(option.width, 0);
		ft_putchar_fd('-');
		printf_cnt++;
	}
	else
	{
		option.width = option.width - option.pre;
		put_blank_zero(option.width, 0);
	}
	option.width = option.pre - len;
	put_blank_zero(option.width, 1);
	printf_cnt += ft_putstr_fd(n);
}

void set_width(char *n, int len)
{
	printf_cnt += len;
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
		printf_cnt += ft_putstr_fd(n);
}

void ft_pointer_address(char **num)
{
	int len;

	printf("\n3. type : %c\n", option.type);
	*num = ft_strjoin("0x", *num);
	len = ft_strlen(*num);
	set_width(*num, len);
}

void put_nbr(unsigned long long n)
{
	printf("\n2. type : %c\n", option.type);
	int len;
	int cl;
	char *num;

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
	ft_change_base(n, cl, &num);
	if (option.type == 'p')
		ft_pointer_address(&num);
	else
	{
		len = ft_strlen(num);
		set_width(num, len);
	}
}
