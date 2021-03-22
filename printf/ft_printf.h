/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:10 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/20 03:07:03 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define TYPES "diuxXcsp"
#define OPTIONS "-0.*123456789"

typedef struct s_option
{
	int minus;
	int zero;
	int width;
	int pre;
	int base;
	char type;
	int neg_num;
} t_option;

int printf_cnt;
t_option option;
va_list ap;

int ft_printf(const char *str, ...);
void init_option();
void do_printf(char *str);
void set_option(char *str, int i);
void set_pre_width(char *str, int i);
void print_str();

void put_char(int c);
void put_blank_zero(int width, int zero);

void put_str(char *str);
void put_blank_str(char *s);

void put_nbr(unsigned long long n);
void ft_pointer_address(char **num);
void set_width(char *n, int len);
void put_right_width(char *n, int len);
void put_left_width(char *n, int len);
void put_pre(char *n, int len);
void ft_change_base(unsigned long long n, char c, char **num);

#endif