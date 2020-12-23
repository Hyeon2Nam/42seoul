/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:39:28 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/23 14:16:48 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    *ft_memset(void *b, int c, size_t len);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_memccpy(void *dst, const void *src, int c, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
size_t  ft_strlen(const char *s);

int main(void)
{
    char a[]="asdfqwer";
    // char b[] = "asdfqwer";

  //printf("%s", ft_memset(a, 'c', sizeof(a)));
  //ft_bzero(a, sizeof(a));
  //printf("%s", ft_memcpy(b, a, sizeof(a)));
  //printf("%s", ft_memccpy(b, a, 'p', sizeof(a)));
//   printf("%s", ft_memmove(b, a, 4));
    // printf("%s", ft_memchr(a, 'q', sizeof(a)));
    // printf("%d", ft_memcmp(a,b,sizeof(a)));
  printf("%zu", ft_strlen(a));
}