/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:16 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/11 14:35:28 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_i(va_list *args, t_prtf *struc, t_flags *flags)
{
	int n;
	(void)flags;

	n = va_arg(*args, int);
	ft_putnbr(n, struc);
}

void	spec_i(va_list *args, t_prtf *struc, t_flags *flags)
{
	conv_i(args, struc, flags);
}