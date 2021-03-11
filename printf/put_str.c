/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:02:58 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/09 23:20:14 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void put_blank_str(char *s)
{
	int len;
	int width;

	len = (int)ft_strlen(s);
	if (option.width < len)
	{
		printf_cnt += len;
		return;
	}
	width = option.width - len;
	put_blank_zero(width, option.zero);
}

void put_str(char *str)
{
	char *s;

	if (!str)
		str = "(null)";
	if (option.pre == -1 || option.pre >= (int)ft_strlen(str))
		option.pre = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (option.pre + 1));
	ft_strlcpy(s, str, option.pre);
	if (option.minus == 1)
	{
		ft_putstr_fd(s, 1);
		put_blank_str(s);
	}
	else
	{
		put_blank_str(s);
		ft_putstr_fd(s, 1);
	}
	free(s);
	s = NULL;
}