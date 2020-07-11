/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:30:13 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/11 13:59:23 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	innit_struct(t_prtf *struc)
{
	struc->i = 0;
	struc->ret = 0;
}

void	innit_flags(t_flags *flags)
{
	flags->pad = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->fill = 0;
	flags->side = 0;
	flags->type = 0;
}

void		ft_getfill(t_flags *flags)
{
	if ((flags->type == 'd' || flags->type == 'i') && (flags->dot || flags->zero))
		flags->fill = '0';
	else if (flags->type == 's' && flags->zero)
		flags->fill = '0';
	else
		flags->fill = ' ';
	if (flags->pad)
		flags->side = 0;
	else
		flags->side = 1;
	if (flags->pad || flags->dot)
		flags->zero = 0;
}