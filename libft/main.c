/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:39:28 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/25 16:45:50 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <string.h>

int main(void)
{
  char a[] = "asdfqwer";
  // char b[] = "qwer";

  // printf("%s", ft_memset(a, 'c', sizeof(a)));
  // ft_bzero(a, sizeof(a));
  // printf("%s", ft_memcpy(b, a, sizeof(a)));
  // printf("%s", ft_memccpy(b, a, 'p', sizeof(a)));
  // printf("%s", ft_memmove(b, a, 4));
  // printf("%s", ft_memchr(a, 'q', sizeof(a)));
  // printf("%d", ft_memcmp(a,b,sizeof(a)));
  // printf("%zu", ft_strlen(a));
  // printf("%zu", ft_strlcpy(a,b,sizeof(b)));
  // printf("%zu", ft_strlcat(a, b, 15));
  // printf("%s", ft_strchr(a, 110));
  // printf("%s", ft_strnstr(a, b, 9));
  // printf("%d\n", ft_strncmp(a, b, 5));
  // printf("%d", ft_atoi(" -1234"));
  // printf("%s", ft_strdup(a));
  printf("%s", ft_substr(a, 4, 9));
}