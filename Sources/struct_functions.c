/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:46:15 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/25 14:34:18 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	innit_struct(t_prtf *struc)
{
	struc->i = 0;
	struc->ret = 0;
	struc->pad = 0;
	struc->dot = 0;
	struc->zero = 0;
	struc->width = 0;
	struc->prec = 0;
	struc->neg = 0;
	struc->len = 0;
	struc->precisneg = 0;
}

void	reset_flags(t_prtf *struc)
{
	struc->pad = 0;
	struc->dot = 0;
	struc->zero = 0;
	struc->width = 0;
	struc->prec = 0;
	struc->neg = 0;
	struc->len = 0;
	struc->precisneg = 0;
}
