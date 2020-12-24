/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:25:59 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/24 23:59:14 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*temp;
	const char	*s;

	temp = dst;
	s = src;
	while (n--)
	{
		if (*s == (const char)c)
		{
			*temp = *s;
			return (dst);
		}
		*temp++ = *s++;
	}
	return (NULL);
}
