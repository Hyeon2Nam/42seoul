/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:41:42 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/21 21:26:20 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *args, ...);

int main()
{
    char a[] = "a";

    // printf("1. %p\n", a);
    // printf("1. %-.5p\n", a);
    // printf("1. %.5p\n", a);
    // printf("1. %.20p\n", a);
    // printf("1. %-.20p\n", a);

    ft_printf("2. %p\n", a);
    ft_printf("2. %-.5p\n", a);
    ft_printf("2. %.5p\n", a);
    ft_printf("2. %.20p\n", a);
    ft_printf("2. %-.20p\n", a);
    ft_printf("\n");
}
//gcc main.c put_*c ft_printf.c ./libft/ft_put*.c ./libft/ft_strlen.c ./libft/ft_isdigit.c ./libft/ft_strchr.c ./libft/ft_strjoin.c ./libft/ft_strlcpy.c
// gcc -Wall -Werror -Wextra main.c put_*c ft_printf.c -L./libft -lft
// gcc main.c put_*c ft_printf.c -L./libft -lft
// 라이브러리 - https://swstar.tistory.com/96