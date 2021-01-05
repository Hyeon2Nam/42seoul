/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:59:16 by riiringim         #+#    #+#             */
/*   Updated: 2021/01/05 13:10:19 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cutnum(char const *s, char c)
{
	size_t cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*from;
	size_t	index;
	size_t	size;

	if (!(ret = (char**)malloc(sizeof(char*) * ft_cutnum(s, c) + 1)))
		return (0);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char*)s;
			while (*s && *s != c)
				++s;
			size = s - from + 1;
			if (!(ret[index] = (char*)malloc(size)))
				return (0);
			ft_strlcpy(ret[index++], from, size);
		}
		else
			++s;
	}
	ret[index] = 0;
	return (ret);
}
