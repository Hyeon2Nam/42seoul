/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:10 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/05 22:09:52 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

# define TYPES "diuxXcsp"
# define OPTIONS "-0.*123456789"

extern int printf_cnt;
extern t_option option;
extern va_list ap; 

typedef struct	s_option
{
	int		left_align;
	int		zero;
	int		width;
	int		pre;
	int		base;
	char 	type;
	int		neg_num;
}				t_option;

int ft_printf(const char *str, ...);
void print_str(char *arags);
void set_pre_width(char *str, int i);
void set_option(char *str, int i);
void do_printf(char *str);
void init_option();
void put_char(int c);
void put_blank_zero(int width, int zero);
void put_string(char *str);
void put_blank_str(char *s);

#endif