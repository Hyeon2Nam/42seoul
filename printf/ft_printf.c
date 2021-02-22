/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:43:38 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/22 23:23:59 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_str(char *arags)
{
	char *temp;

	if (option.type == 'c')
	{
		printf_cnt++;
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	if (option.type == 's')
	{
		temp = va_arg(ap, char *);
		printf_cnt += ft_strlen(temp);
		ft_putstr_fd(temp, 1);
	}
	if (option.type == 'd' || option.type == 'i')
		put_int();
	if (option.type == 'u' || option.type == 'x' || option.type == 'X')
		put_unbr();
	if (option.type == 'p')
		put_ptr();
}

void set_option(char *str, int i)
{
	if (str[i] == '-')
		option.left_align = 1;
	if (str[i] == '0')
		option.zero = 1;
	if (str[i] == '.')
		option.pre = va_arg(ap, int);
	if (str[i] == '*')
	{
		option.width = va_arg(ap, int);
		if (option.width < 0)
		{
			option.width *= -1;
			option.left_align = 1;
		}
	}
	if (ft_isdigit(str[i]))
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
			while (ft_strchr(options, str[++i]) || ft_strchr(types, str[i]))
			{
				if (ft_strchr(options, str[i]))
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
	option.pre = 0;
	option.base = 10;
	option.type = ' ';
}

int ft_printf(const char *str, ...)
{
	va_start(ap, str);
	init_option();
	do_printf((char *)str);
	va_end(ap);
	return (printf_cnt);
}
