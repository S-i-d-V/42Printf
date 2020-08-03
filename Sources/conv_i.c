/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:16 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/03 15:25:43 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_i(va_list *args, t_prtf *struc)
{
	int n;

	n = va_arg(*args, int);
	ft_putnbr(n, struc);
}

void	spec_i(va_list *args, t_prtf *struc)
{
	conv_i(args, struc);
}