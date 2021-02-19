/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:43:38 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/19 20:46:44 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void do_printf(va_list ap, char *args)
{
	int i;
	t_option option;

	i = 0;
	while (args[i] != 0)
	{
		if (args[i] == '%')
		{
			if (args[i + 1] == )
		}
		else
		{
			printf_cnt++;
			ft_putchar_fd(args[i], 1);
		}

		i++;
	}
}

int ft_printf(const char *args, ...)
{
	va_list ap;
	va_start(ap, args);
	do_printf(ap, (char *)args);
	va_end(ap);
	return (printf_cnt);
}
