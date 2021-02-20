/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:43:38 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/20 11:46:29 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void set_option(va_list ap, char *args, int i)
{
	if (args[i] == '-')
		option.dir = 'l';
	if (args[i] == '0')
		option.zero = 1;
	if (args[i] == '.')
		option.pre = args[i + 1];
	if (args[i] >= '1' && args[i] <= '9')
		option.width = va_arg(ap, int);
}

void do_printf(va_list ap, char *args)
{
	int i;

	i = 0;
	while (args[i] != 0)
	{
		if (args[i] == '%')
		{
			if (ft_strchr(options, args[i + 1]))
				set_option(ap, args, i + 1);
			if (ft_strchr(types, args[i + 1]))
				set_type(ap, args[i + 1]);
		}
		else
		{
			printf_cnt++;
			ft_putchar_fd(args[i], 1);
		}
		i++;
	}
}

void set_option()
{
	option.dir = 'r';
	option.width = 0;
	option.pre = 0;
	option.base = 10;
	option.type = '/0';
}

int ft_printf(const char *args, ...)
{
	va_list ap;
	va_start(ap, args);
	set_option();
	do_printf(ap, (char *)args);
	va_end(ap);
	return (printf_cnt);
}
