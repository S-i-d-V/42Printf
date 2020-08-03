/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:30 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/03 15:25:43 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_x(va_list *args, t_prtf *struc)
{
	unsigned int n;

	n = va_arg(*args, unsigned int);
	ft_puthlow(n, struc);
}

void	spec_x(va_list *args, t_prtf *struc)
{
	conv_x(args, struc);
}