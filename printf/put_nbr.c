/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:46:09 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/21 21:24:09 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_len(unsigned long long value)
{
	int res;

	res = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= option.base;
		res++;
	}
	return (res);
}

char *ft_zero()
{
	char *num;
	int i;

	if (option.pre == -1)
		option.pre = 1;
	num = (char *)malloc(sizeof(char) * (option.pre + 1));
	num[option.pre] = 0;
	i = 0;
	while (i < option.pre)
		num[i++] = '0';
	return (num);
}

void ft_change_base(unsigned long long n, char c, char **num)
{
	int r;
	int len;
	int i;

	len = ft_len(n);
	*num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return;
	i = 1;
	(*num)[len] = 0;
	if (n == 0)
		*num = ft_zero();
	while (n > 0)
	{
		r = n % option.base;
		n /= option.base;
		if (r < 10)
			(*num)[len - i] = r + '0';
		else
			(*num)[len - i] = r - 10 + c;
		i++;
	}
}

void put_pre(char *n, int len)
{
	int width;

	if (option.neg_num)
	{
		ft_putchar_fd('-');
		printf_cnt++;
	}
	width = option.pre - len + 1;
	put_blank_zero(width, 1);
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
	width = option.width - len + 1;
	printf_cnt += ft_putstr_fd(n);
	put_blank_zero(width - minus, option.zero);
}

void put_right_width(char *n, int len)
{
	option.width -= len;
	if (option.neg_num)
	{
		put_blank_zero(option.width, option.zero);
		ft_putchar_fd('-');
		printf_cnt++;
	}
	else
		put_blank_zero(option.width + 1, option.zero);
	printf_cnt += ft_putstr_fd(n);
}

void set_width(char *n, int len)
{
	if (option.zero && option.width > option.pre)
		option.zero = 0;
	if (option.width != 0 && option.pre < option.width)
	{
		if (option.minus)
			put_left_width(n, len);
		else
			put_right_width(n, len);
	}
	else
		put_right_width(n, len);
}

void ft_pointer_address(char **num)
{
	int len;

	*num = ft_strjoin("0x", *num);
	len = ft_strlen(*num);
	set_width(*num, len);
}

void put_nbr(unsigned long long n)
{
	int len;
	int cl;
	char *num;

	if (option.type == 'x' || option.type == 'X' || option.type == 'p')
		option.base = 16;
	if ((option.type == 'i' || option.type == 'd') && (int)n < 0)
	{
		option.neg_num = 1;
		n *= -1;
	}
	if (option.type == 'X')
		cl = 'A';
	else
		cl = 'a';
	ft_change_base(n, cl, &num);
	if (option.type == 'p')
		ft_pointer_address(&num);
	else
	{
		len = ft_strlen(num);
		set_width(num, len);
	}
	free(num);
}
