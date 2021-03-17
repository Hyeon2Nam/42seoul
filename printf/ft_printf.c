/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:49:41 by hyenam            #+#    #+#             */
/*   Updated: 2021/03/17 20:59:15 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_str()
{
    if (option.type == 'c')
        put_char(va_arg(ap, int));
    else if (option.type == 's')
        put_str(va_arg(ap, char *));
    else if (option.type == 'd' || option.type == 'i')
        put_nbr(va_arg(ap, int));
    else if (option.type == 'u' || option.type == 'x' || option.type == 'X')
        put_nbr(va_arg(ap, unsigned int));
    else if (option.type == 'p')
        put_nbr(va_arg(ap, unsigned long long));
}

void set_pre_width(char *str, int i)
{
    if (ft_isdigit(str[i]))
    {
        if (option.pre == -1)
            option.width = option.width * 10 + str[i] - '0';
        else
            option.pre = option.pre * 10 + str[i] - '0';
    }
    else
    {
        if (option.pre == -1)
        {
            option.width = va_arg(ap, int);
            if (option.width < 0)
            {
                option.minus = 1;
                option.width *= -1;
            }
        }
        else
            option.pre = va_arg(ap, int);
    }
}

void set_option(char *str, int i)
{
    if (str[i] == '-')
        option.minus = 1;
    if (str[i] == '0' && option.pre == -1 && option.width == 0)
        option.zero = 1;
    if (str[i] == '.')
        option.pre = 0;
    if (ft_isdigit(str[i]) || str[i] == '*')
        set_pre_width(str, i);
    if (str[i] == '%')
        printf_cnt += ft_putchar_fd(str[i]);
}

void do_printf(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (str[i] == '%')
        {
            while (ft_strchr(OPTIONS, str[++i]) || ft_strchr(TYPES, str[i]))
            {
                if (ft_strchr(OPTIONS, str[i]))
                    set_option(str, i);
                else
                {
                    option.type = str[i];
                    break;
                }
            }
            print_str();
        }
        else
            printf_cnt += ft_putchar_fd(str[i]);
    }
    // printf("\ncnt : %d", printf_cnt);
}

void init_option()
{
    option.minus = 0;
    option.zero = 0;
    option.width = 0;
    option.pre = -1;
    option.base = 10;
    option.type = 0;
    option.neg_num = 0;
}

int ft_printf(const char *str, ...)
{
    printf_cnt = 0;
    va_start(ap, str);
    init_option();
    do_printf((char *)str);
    va_end(ap);
    return (printf_cnt);
}
