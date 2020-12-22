/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:49:46 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/22 21:50:17 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp;
	const char	*str;

	if (dst <= src)
	{
		temp = dst;
		str = src;
		while (len--)
			*temp++ = *str++;
	}
	else
	{
		temp = dst;
		temp += len;
		str = src;
		src += len;
		while (len--)
			*--temp = *--str;
	}
	return (dst);
}
