/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:46:09 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/07 12:39:22 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_len(unsigned long long value, t_option *option)
{
	int res;

	res = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= option->base;
		res++;
	}
	return (res);
}

char *ft_zero(t_option *option)
{
	char *num;
	int i;

	if (option->zero && option->pre < 0 && option->width > 0)
		option->pre = option->width;
	if (option->pre < 0)
		option->pre = 1;
	num = (char *)malloc(sizeof(char) * (option->pre + 1));
	num[option->pre] = 0;
	i = 0;
	while (i < option->pre)
		num[i++] = '0';
	return (num);
}

void ft_change_base(unsigned long long n, char c, char **num, t_option *option)
{
	int r;
	int len;
	int i;

	len = ft_len(n, option);
	*num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return;
	i = 1;
	(*num)[len] = 0;
	if (n == 0)
		*num = ft_zero(option);
	while (n > 0)
	{
		r = n % option->base;
		n /= option->base;
		if (r < 10)
			(*num)[len - i] = r + '0';
		else
			(*num)[len - i] = r - 10 + c;
		i++;
	}
}

void put_left_width(char *n, int len, t_option *option)
{
	int minus;
	int width;
	int result;

	result = 0;
	minus = 0;
	if (option->neg_num)
	{
		ft_putchar_fd('-');
		result++;
		minus = 1;
	}
	width = option->width - len + 1;
	result += ft_putstr_fd(n);
	put_blank_zero(width - minus, option->zero);
	// result += put_blank_zero(width - minus, option->zero);
	return (result);
}

void put_right_width(char *n, int len, t_option *option)
{
	int result;

	result = 0;
	option->width -= len;
	if (option->neg_num)
	{
		if (!option->zero)
			put_blank_zero(option->width, 0);
			// result += put_blank_zero(option->width, 0);
		ft_putchar_fd('-');
		if (option->zero)
			put_blank_zero(option->width, option->zero);
			// result += put_blank_zero(option->width, option->zero);
		result++;
	}
	else
		put_blank_zero(option->width + 1, option->zero);
		// result += put_blank_zero(option->width + 1, option->zero);
	result += ft_putstr_fd(n);
	return (result);
}

void set_width(char *n, int len, t_option *option)
{
	int result;

	result = 0;
	if (option->pre >= 0)
		option->zero = 0;
	if (option->minus)
		put_left_width(n, len, option);
		// result += put_left_width(n, len, option);
	else
		put_right_width(n, len, option);
		// result += put_right_width(n, len, option);
	return (result);
}

char *set_pre(char *n, int len, t_option *option)
{
	char *new_num;
	int i;
	int j;

	if (option->pre > len)
	{
		new_num = (char *)malloc(sizeof(char) * (option->pre + 1));
		if (!new_num)
			return (NULL);
		i = 0;
		new_num[option->pre] = 0;
		while (len + i < option->pre)
			new_num[i++] = '0';
		j = 0;
		while (j < len)
			new_num[i++] = n[j++];
		return (new_num);
	}
	else
		return (n);
}

void ft_pointer_address(char **num, t_option *option)
{
	int len;
	int result;

	result = 0;
	*num = ft_strjoin("0x", *num);
	len = ft_strlen(*num);
	set_width(*num, len, option);
	// result += set_width(*num, len, option);
	return (result);
}

void put_nbr(unsigned long long n, t_option *option)
{
	int len;
	int cl;
	char *num;
	// int result;

	// result = 0;
	if (option->type == 'x' || option->type == 'X' || option->type == 'p')
		option->base = 16;
	if ((option->type == 'i' || option->type == 'd') && (int)n < 0)
	{
		option->neg_num = 1;
		n *= -1;
	}
	if (option->type == 'X')
		cl = 'A';
	else
		cl = 'a';
	ft_change_base(n, cl, &num, option);
	num = set_pre(num, ft_strlen(num), option);
	if (option->type == 'p')
		ft_pointer_address(&num, option);
		// result += ft_pointer_address(&num, option);
	else
	{
		len = ft_strlen(num);
		set_width(num, len, option);
		// result += set_width(num, len, option);
	}
	free(num);
	// return (result);
	//
}
