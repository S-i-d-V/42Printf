/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:30:13 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 16:08:13 by ugtheven         ###   ########.fr       */
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
	flags->wc = 0;
	flags->prec = 0;
	flags->len = 0;
	flags->fill = 0;
}
