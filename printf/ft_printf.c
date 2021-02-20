/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:43:38 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/20 13:44:36 by hyenam           ###   ########.fr       */
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
		put_arg_int();
	if (option.type == 'u')
		put_arg_uint();
	if (option.type == 'x')
		put_arg_hex();
	if (option.type == 'X')
		put_arg_hex();
	if (option.type == 'p')
		put_arg_ptr();
}

int set_option(char *str, int i)
{
	if (str[i] == '-')
		option.align = 'l';
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
			option.align = 'l';
		}
	}
	if (str[i] == '%')
	{
		ft_putchar_fd(str[i], 1);
		printf_cnt++;
	}
	return (0);
}

void do_printf(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			while (ft_strchr(options, str[i + 1]) || ft_strchr(types, str[i + 1]))
			{
				if (ft_strchr(options, str[i + 1]))
					i += set_option(str, i + 1);
				else
					option.type = str[i + 1];
				i++;
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
	option.align = 'r';
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
