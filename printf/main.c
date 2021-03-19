/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:41:42 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/20 02:06:40 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *args, ...);

int main()
{
    int a = -123;

    // printf("1. %d\n", a);
    // printf("%5.2d\n", a);
    // printf("%2.5d\n", a);
    // printf("%-5.2d\n", a);
    // printf("%-2.5d\n", a);
    // printf("%05.2d\n", a);
    // printf("%02.5d\n", a);
    // printf("%-5d\n", a);
    // printf("%0.5d\n", a);
    
    ft_printf("2. %d\n", a);
    // ft_printf("%5.2d\n", a);
    // ft_printf("%2.5d\n", a);
    // ft_printf("%-5.2d\n", a);
    // ft_printf("%-2.5d\n", a);
    // ft_printf("%05.2d\n", a);
    // ft_printf("%02.5d\n", a);
    // ft_printf("%-2.5d\n", a);
    // ft_printf("%-5d\n", a);
    // ft_printf("%0.5d\n", a);
    // ft_printf("\n");
}
//gcc main.c put_*c ft_printf.c ./libft/ft_put*.c ./libft/ft_strlen.c ./libft/ft_isdigit.c ./libft/ft_strchr.c ./libft/ft_strjoin.c ./libft/ft_strlcpy.c
// gcc -Wall -Werror -Wextra main.c put_*c ft_printf.c -L./libft -lft
// gcc main.c put_*c ft_printf.c -L./libft -lft