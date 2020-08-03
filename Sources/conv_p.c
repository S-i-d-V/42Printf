/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:51:48 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/03 15:25:43 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_p(va_list *args, t_prtf *struc)
{
	unsigned long long n;

	n = va_arg(*args, unsigned long long);
	ft_putstr("0x", struc);
	ft_puthlow(n, struc);
}

void	spec_p(va_list *args, t_prtf *struc)
{
	conv_p(args, struc);
}