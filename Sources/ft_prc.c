/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:39 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 01:38:28 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	ft_prc(va_list *args, t_prtf *struc)
{
	(void)args;
	if (struc->pad)
	{
		ft_putchar('%', struc);
		ft_fill(' ', struc->width - 1, struc);
	}
	else if (struc->dot)
	{
		ft_fill(' ', struc->width - 1, struc);
		ft_putchar('%', struc);
	}
	else if (struc->zero)
	{
		ft_fill('0', struc->width - 1, struc);
		ft_putchar('%', struc);
	}
	else if (struc->width && !struc->zero && !struc->pad)
	{
		ft_fill(' ', struc->width - 1, struc);
		ft_putchar('%', struc);
	}
	else
		ft_putchar('%', struc);
}
