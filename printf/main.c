/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:41:42 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/17 20:59:09 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *args, ...);

int main()
{
    char a[] = "asdf";

    ft_printf("%05s\n", a);
    ft_printf("%-05s\n", a);
    ft_printf("%-5s\n", a);
    ft_printf("%5s\n", a);
    ft_printf("%-*s\n",  5,  a);
	ft_printf("%*s\n",  5,  a);
	ft_printf("%0*s\n",  5,  a);
	ft_printf("%0-*s\n",  5,  a);   
}
//gcc main.c put_*c ft_printf.c ./libft/ft_put*.c ./libft/ft_strlen.c ./libft/ft_isdigit.c ./libft/ft_strchr.c ./libft/ft_strjoin.c ./libft/ft_strlcpy.c
// gcc main.c put_*c ft_printf.c -L./libft -lft