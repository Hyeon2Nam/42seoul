/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:17:43 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/07 12:18:04 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_option		init_option()
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