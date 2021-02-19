/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:10 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/18 20:34:24 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct	t_option
{
	char	flag;
	int		width;
	int		pre;
	int		base;
	char 	type;
}				option;

extern char *types = "diuxXcsp";
extern int printf_cnt;

#endif