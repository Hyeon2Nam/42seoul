/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:35:06 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/11 22:06:22 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_change_base(unsigned int n, int base)
{
	int r;

	r = n % base;
	n /= base;
	if (n > 0)
		change_base(n, base);

	if (r < 10)
		printf("%d", r);
	else
		printf("%c", r - 10 + 'A');
}

int ft_printf(const char *args, ...)
{
	va_list ap;
	int i;

	i = -1;
	va_start(ap, args);
	while (args[++i])
	{
		if (args[i] == '%')
		{
			if (args[i + 1] == 'd' || args[i + 1] == 'i')
			{
				ft_putnbr_fd(va_arg(ap, int), 1);
				i++;
			}
			if (args[i + 1] == 'u')
			{
				ft_putnbr_fd((unsigned int)va_arg(ap, int), 1);
				i++;
			}
			if (args[i + 1] == 'o')
			{
				ft_change_base(va_arg(ap, int), 8);
				i++;
			}
		}
		else
			ft_putchar_fd(args[i], 1);
	}
	va_end(ap);
	return (1);
}

int main(void)
{
	ft_printf("%o1232133\n", -123);
	printf("%o\n", -123);
}
