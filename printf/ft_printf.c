/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:35:06 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/16 21:26:44 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void ft_change_unsigned_base(unsigned int n, int base, int cl)
{
	int r;

	r = n % base;
	n /= base;
	if (n > 0)
		ft_change_unsigned_base(n, base, cl);

	if (r < 10)
		ft_putnbr_fd(r, 1);
	else
		ft_putchar_fd(r - 10 + (cl == 1 ? 'A' : 'a'), 1);
}

int ft_printf(const char *args, ...)
{
	va_list ap;
	int i;

	i = -1;
	va_start(ap, args);
	while (args[++i])
	{
		if (args[i] == '%') // 따로 서식 지정자 체크하는걸 만들어야 할듯 근데 일단 플래크 부터
		{
			i++;
			if (args[i] == 'd' || args[i + 1] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			if (args[i] == 'u')
				ft_putnbr_fd((unsigned int)va_arg(ap, int), 1);
			if (args[i] == 'x')
				ft_change_unsigned_base(va_arg(ap, int), 16, 0);
			if (args[i] == 'X')
				ft_change_unsigned_base(va_arg(ap, int), 16, 1);
			if (args[i] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			if (args[i] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			if (args[i] == 'p')
				;
			if (args[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(args[i], 1);
	}
	va_end(ap);
	return (1);
}

int main(void)
{
	char tab[] = "qwer";
	write_ptr(tab);
	// print_memory(tab, sizeof(tab));
	// ft_printf("%c\n", 'c');
	printf("\n%p\n", tab);
}
