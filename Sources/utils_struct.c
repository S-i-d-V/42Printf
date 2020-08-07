/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:30:13 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/07 14:07:30 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	innit_struct(t_prtf *struc)
{
	struc->i = 0;
	struc->ret = 0;
	struc->len = 0;
	struc->pad = 0;
	struc->zero = 0;
	struc->width = 0;
	struc->dot = 0;
	struc->fill = 0;
	struc->side = 0;
	struc->type = 0;
	struc-> neg = 0;
}

void	reset_flags(t_prtf *struc)
{
	struc->len = 0;
	struc->pad = 0;
	struc->zero = 0;
	struc->width = 0;
	struc->dot = 0;
	struc->fill = 0;
	struc->side = 0;
	struc->type = 0;
	struc->neg = 0;
}

void		ft_getfill(t_prtf *struc)
{
	if ((struc->type == 'd' || struc->type == 'i') && (struc->dot || struc->zero))
		struc->fill = '0';
	else if (struc->type == 's' && struc->zero)
		struc->fill = '0';
	else
		struc->fill = ' ';
	if (struc->pad)
		struc->side = 0;
	else
		struc->side = 1;
	if (struc->pad || struc->dot)
		struc->zero = 0;
}