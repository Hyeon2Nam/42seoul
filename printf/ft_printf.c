/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:43:38 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/23 16:43:10 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_str(char *arags)
{
	if (option.type == 'c')
		put_char(va_arg(ap, int));
	if (option.type == 's')
		put_str(va_arg(ap, char *));
	if (option.type == 'd' || option.type == 'i')
		put_int(va_arg(ap, int));
	if (option.type == 'u' || option.type == 'x' || option.type == 'X')
		put_unbr(va_arg(ap, unsigned int));
	if (option.type == 'p')
		put_ptr(va_arg(ap, unsigned long long));
}

void set_pre_width(char *str, int i)
{
	if (ft_isdigit(str[i]))
	{
		if (option.pre == -1)
			option.width = option.width * 10 + str[i] - '0';
		else
			option.pre = option.pre * 10 + str[i] - '0';
	}
	else
	{
		if (option.pre == -1)
		{
			option.width = va_arg(ap, int);
			if (option.width < 0)
			{
				option.left_align = 1;
				option.width *= -1;
			}
		}
		else
			option.pre = va_arg(ap, int);
	}
}

void set_option(char *str, int i)
{
	if (str[i] == '-')
		option.left_align = 1;
	if (str[i] == '0' && option.pre == -1 && option.width == 0)
		option.zero = 1;
	if (str[i] == '.')
		option.pre = 0;
	if (ft_isdigit(str[i]) || str[i] == '*')
		set_pre_width(str, i);
	if (str[i] == '%')
	{
		ft_putchar_fd(str[i], 1);
		printf_cnt++;
	}
}

void do_printf(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			while (ft_strchr(OPTIONS, str[++i]) || ft_strchr(TYPES, str[i]))
			{
				if (ft_strchr(OPTIONS, str[i]))
					set_option(str, i);
				else
					option.type = str[i];
			}
			print_str(str);
		}
		else
		{
			printf_cnt++;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
}

void init_option()
{
	option.left_align = 0;
	option.zero = 0;
	option.width = 0;
	option.pre = -1;
	option.base = 10;
	option.type = 0;
}

int ft_printf(const char *str, ...)
{
	va_start(ap, str);
	init_option();
	do_printf((char *)str);
	va_end(ap);
	return (printf_cnt);
}
