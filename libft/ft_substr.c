/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:37:59 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/28 19:49:31 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	size_t clen;

	clen = len - start;
	str = (char *)malloc(sizeof(char) * clen);
	if (!str)
		return (NULL);
	else
		ft_strlcpy(str, &s[start], clen);
	return (str);
}