/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:30:13 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 01:08:57 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	innit_struct(t_prtf *struc)
{
	struc->i = 0;
	struc->ret = 0;
	struc->pad = 0;
	struc->zero = 0;
	struc->wc = 0;
	struc->prec = 0;
	struc->fill = 0;
}

void	reset_flags(t_prtf *struc)
{
	struc->pad = 0;
	struc->zero = 0;
	struc->wc = 0;
	struc->prec = 0;
	struc->fill = 0;
}
