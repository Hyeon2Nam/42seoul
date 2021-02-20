/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:46:09 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/20 13:52:00 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_len(long long value)
{
    int res;

    res = 0;
    if (value < 0)
    {
        value *= -1;
        res++;
    }
    while (value > 0)
    {
        value /= 10;
        res++;
    }
    return (res);
}

void put_arg_int()
{
    int value;
    int len;

    value = va_arg(ap, int);
    len = ft_len(value);
}

void put_arg_uint()
{
}

void put_arg_hex()
{
}

void put_arg_ptr()
{
}
