/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:11:43 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/08 13:31:30 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_puthlow(unsigned long long nb, t_prtf *struc)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthlow(nb / 16, struc);
	ft_putchar(base[(nb % 16)], struc);
}

void		ft_puthup(unsigned long long nb, t_prtf *struc)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
		ft_puthup(nb / 16, struc);
	ft_putchar(base[(nb % 16)], struc);
}

void		ft_putui(unsigned int nb, t_prtf *struc)
{
	if (nb == 0)
		ft_putchar('0', struc);
	else if (nb >= 10)
	{
		ft_putui(nb / 10, struc);
		ft_putchar(nb % 10 + 48, struc);
	}
	else
		ft_putchar(nb + 48, struc);
}
