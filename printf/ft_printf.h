/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:10 by hyenam            #+#    #+#             */
/*   Updated: 2021/02/22 21:12:05 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct	s_option
{
	int		left_align;
	int		zero;
	int		width;
	int		pre;
	int		base;
	char 	type;
}				t_option;

typedef struct s_
{
	/* data */
};



extern char types[] = "diuxXcsp";
extern char options[] = "-0.*123456789";
extern int printf_cnt;
extern t_option option;
extern va_list ap;
 

#endif