/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:39:28 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/22 15:56:19 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    *ft_memset(void *b, int c, size_t len);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_memccpy(void *dst, const void *src, int c, size_t n);

int main(void)
{
  char a[]="asdfqwer";
  char b[] = "zxcvzxcv";

  //printf("%s", ft_memset(a, 'c', sizeof(a)));
  //ft_bzero(a, sizeof(a));
  //printf("%s", ft_memcpy(b, a, sizeof(a)));
  printf("%s", ft_memccpy(b, a, 'p', sizeof(a)));
}