/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:41:42 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/18 20:46:47 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *args, ...);

int main()
{
    char a[] = "asdf";

    ft_printf("%s", a);
    // ft_printf("%.2s\n", a);
    // ft_printf("%-08.2s\n", a);
    // ft_printf("%-8.2s\n", a);
    // ft_printf("%8.2s\n", a);
    // ft_printf("%-*.2s\n",  8,  a);
	// ft_printf("%*.2s\n",  8,  a);
	// ft_printf("%0*.2s\n",  8,  a);
	// ft_printf("%0-*.2s\n",  8,  a);   
}
//gcc main.c put_*c ft_printf.c ./libft/ft_put*.c ./libft/ft_strlen.c ./libft/ft_isdigit.c ./libft/ft_strchr.c ./libft/ft_strjoin.c ./libft/ft_strlcpy.c
// gcc main.c put_*c ft_printf.c -L./libft -lft