/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:02:58 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/18 20:47:02 by hyenam           ###   ########.fr       */
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
		option.width = len;
		return;
	}
	width = option.width - len + 1;
	put_blank_zero(width, option.zero);
}

void put_str(char *str)
{
	char *s;

	if (str == NULL)
		str = "(null)";
	if (option.pre == -1 || option.pre >= (int)ft_strlen(str))
		option.pre = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (option.pre + 1));
	ft_strlcpy(s, str, option.pre + 1);
	if (option.minus == 1)
	{
		ft_putstr_fd(s);
		put_blank_str(s);
	}
	else
	{
		put_blank_str(s);
		// printf("\ncnt : %d", printf_cnt); 
		ft_putstr_fd(s);
		// printf("\ncnt : %d", printf_cnt);
	}
	free(s);
	s = NULL;
}