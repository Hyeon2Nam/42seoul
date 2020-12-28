/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:51:31 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/28 20:00:34 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = ft_strlen(s);
	while (str[i] != (char)c && i >= 0)
		i--;
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}