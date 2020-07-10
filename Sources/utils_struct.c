/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:30:13 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/10 14:38:46 by ugtheven         ###   ########.fr       */
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
