/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:02:35 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/24 23:59:24 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *src1;
	const unsigned char *src2;

	src1 = s1;
	src2 = s2;
	while (n--)
		if (*src1++ != *src2++)
			return (src1 - src2);
	return (0);
}
