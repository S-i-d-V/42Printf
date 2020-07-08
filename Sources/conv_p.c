/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:51:48 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/07 22:47:04 by ugotheveny       ###   ########.fr       */
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
