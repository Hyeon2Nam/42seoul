/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:59:16 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/31 22:45:59 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cutnum(char const *s, char c)
{
	size_t i;
	size_t cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i])
			i++;
	}
	return (cnt);
}

static char		**ft_free(char **s, size_t cnt)
{
	size_t i;

	i = 0;
	while (i < cnt)
		free(s[i++]);
	free(s);
	return (NULL);
}

static int		ft_cstrlen(const char *s, char c, size_t i)
{
	size_t len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static char		**ft_action_split(const char *s, char c, char **str, size_t len)
{
	size_t i;
	size_t j;
	size_t cnt;

	i = 0;
	cnt = 0;
	while (s[i] && cnt < len)
	{
		j = 0;
		while (s[i] == c)
			i++;
		str[cnt] = (char *)malloc(sizeof(char) * ft_cstrlen(s, c, i) + 1);
		if (!str[cnt])
			return (ft_free(str, cnt));
		while (s[i] && s[i] != c)
			str[cnt][j++] = s[i++];
		str[cnt][j] = 0;
		cnt++;
	}
	str[cnt] = 0;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	clen;

	if (!s)
		return (NULL);
	clen = ft_cutnum(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (clen + 1))))
		return (NULL);
	return (ft_action_split(s, c, str, clen));
}
