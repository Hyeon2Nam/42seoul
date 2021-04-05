/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:49:41 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/05 18:38:18 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str(va_list ap, t_option *option)
{
    int result;

    result = 0;
    if (option->zero == 1 && option->minus == 1)
        option->zero = 0;
    if (option->type == 'c')
        result += put_char(va_arg(ap, int), option);
    else if (option->type == 's')
        result += put_str(va_arg(ap, char *), option);
    else if (option->type == '%')
        result += put_str("%", option);
    else if (option->type == 'd' || option->type == 'i')
        result += put_nbr(va_arg(ap, int), option);
    else if (option->type == 'u' || option->type == 'x' || option->type == 'X')
        result += put_nbr(va_arg(ap, unsigned int), option);
    else if (option->type == 'p')
        result += put_nbr(va_arg(ap, unsigned long long), option);
    return (result);
}

void set_pre_width(char *str, int i, va_list ap, t_option *option)
{
    if (ft_isdigit(str[i]))
    {
        if (option->pre == -1)
            option->width = option->width * 10 + str[i] - '0';
        else
            option->pre = option->pre * 10 + str[i] - '0';
    }
    else
    {
        if (option->pre == -1)
        {
            option->width = va_arg(ap, int);
            if (option->width < 0)
            {
                option->minus = 1;
                option->width *= -1;
                option->zero = 0;
            }
        }
        else
            option->pre = va_arg(ap, int);
    }
}

void set_option(char *str, int i, va_list ap, t_option *option)
{
    if (str[i] == '-')
        option->minus = 1;
    if (str[i] == '0' && option->pre == -1 && option->width == 0)
        option->zero = 1;
    if (str[i] == '.')
        option->pre = 0;
    if (ft_isdigit(str[i]) || str[i] == '*')
        set_pre_width(str, i, ap, option);
}

t_option init_option()
{
    t_option option;

    option.minus = 0;
    option.zero = 0;
    option.width = 0;
    option.pre = -1;
    option.base = 10;
    option.type = 0;
    option.neg_num = 0;
    return (option);
}

int do_printf(char *str, va_list ap)
{
    int i;
    int result;
    t_option *option;

    i = -1;
    result = 0;
    option = (t_option *)malloc(sizeof(t_option) * 1);
    while (str[++i])
    {
        *option = init_option();
        if (str[i] == '%')
        {
            while (str[++i] && (ft_strchr(OPTIONS, str[i]) || ft_strchr(TYPES, str[i]) || str[i] == '%'))
            {
                if (ft_strchr(OPTIONS, str[i]))
                    set_option(str, i, ap, option);
                else
                {
                    option->type = str[i];
                    break;
                }
            }
            result += print_str(ap, option);
        }
        else
            result += ft_putchar_fd(str[i]);
    }
    return (result);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    int result;

    result = 0;
    va_start(ap, str);
    result = do_printf((char *)str, ap);
    va_end(ap);
    return (result);
}
