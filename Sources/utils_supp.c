/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_supp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:11:43 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/06/25 01:21:35 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

unsigned int	ft_itoui(unsigned int nb)
{
	unsigned int res;

	res = 4294967295;
	if (nb < 0)
	{
		res = res - nb;
		return (res);
	}
	res = nb;
	return (res);
}

void		ft_puthlow(unsigned int nb)
{
	char *base;

	base = "0123456789abcdef";
	if (nb < 0)
		nb = ft_itoui(nb);
	if (nb >= 16)
		ft_puthlow(nb / 16);
		ft_putchar(base[(nb % 16)]);
}

void	ft_puthup(unsigned int nb)
{
	char *base;

	base = "0123456789abcdef";
	if (nb < 0)
		nb = ft_itoui(nb);
	if (nb >= 16)
		ft_dtohup(nb / 16);
		ft_putchar(base[(nb % 16)]);
}

void	ft_putui(unsigned int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else if (nb < 0)
	{
		nb = ft_itoui(nb);
	}
	else if (nb >= 10)
	{
		ft_putui(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}