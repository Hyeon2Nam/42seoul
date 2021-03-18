/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:21:45 by riiringim         #+#    #+#             */
/*   Updated: 2021/03/14 15:20:06 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_putstr_fd(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		ft_putchar_fd(*s++);
		i++;
	}
	return (i);
}