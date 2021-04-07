/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:02:58 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/07 12:24:07 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void put_blank_str(char *s, t_option *option)
{
	int len;
	int width;
	// int result;

	// result = 0;
	len = (int)ft_strlen(s);
	if (option->width < len)
	{
		option->width = len;
		return (0);
	}
	width = option->width - len + 1;
	// result += put_blank_zero(width, option->zero);
	put_blank_zero(width, option->zero);
	return (result);
}

void put_str(char *str, t_option *option)
{
	char *s;
	// int result;

	// result = 0;
	if (str == NULL)
		str = "(null)";
	if (option->pre != 0 && option->pre < 0)
		option->pre = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (option->pre + 1));
	ft_strlcpy(s, str, option->pre + 1);
	if (option->minus == 1)
	{
		result += ft_putstr_fd(s);
		put_blank_str(s, option);
		// result += put_blank_str(s, option);
	}
	else
	{
		put_blank_str(s, option);
		// result += put_blank_str(s, option);
		result += ft_putstr_fd(s);
	}
	free(s);
	s = NULL;
	// return (result);
}