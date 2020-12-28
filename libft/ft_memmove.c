/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:49:46 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/28 18:09:15 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (src < dst)
		while (n--)
			*(unsigned char*)(dst + n) = *(unsigned char*)(src + n);
	else
		ft_memcpy(dst, src, n);
	return (dst);
}