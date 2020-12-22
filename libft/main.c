/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:39:28 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/22 13:23:55 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    *ft_memset(void *str, int value, unsigned int size);

int main(void)
{
  int a[]={1,1,1,1,1,1,1};

  printf("%s", ft_memset(a, 0, sizeof(a)));
}