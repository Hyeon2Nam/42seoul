/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:41:42 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/18 21:09:30 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *args, ...);

int main()
{
    int a = 123;

    ft_printf("%d\n", a);
}
//gcc main.c put_*c ft_printf.c ./libft/ft_put*.c ./libft/ft_strlen.c ./libft/ft_isdigit.c ./libft/ft_strchr.c ./libft/ft_strjoin.c ./libft/ft_strlcpy.c
// gcc main.c put_*c ft_printf.c -L./libft -lft