/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:10 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/05 20:26:16 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
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

int ft_printf(const char *str, ...);
t_option init_option();
int do_printf(char *str, va_list ap);
void set_option(char *str, int i, va_list ap, t_option *option);
void set_pre_width(char *str, int i, va_list ap, t_option *option);
int print_str(va_list ap, t_option *option);

int put_char(int c, t_option *option);
int put_blank_zero(int width, int zero);

int put_str(char *str, t_option *option);
int put_blank_str(char *s, t_option *option);

int put_nbr(unsigned long long n, t_option *option);
int ft_pointer_address(char **num, t_option *option);
char *set_pre(char *n, int len, t_option *option);
int set_width(char *n, int len, t_option *option);
int put_right_width(char *n, int len, t_option *option);
int put_left_width(char *n, int len, t_option *option);
void ft_change_base(unsigned long long n, char c, char **num, t_option *option);
char *ft_zero(t_option *option);
int ft_len(unsigned long long value, t_option *option);

#endif