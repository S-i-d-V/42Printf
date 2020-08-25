/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:08 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/25 14:04:48 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_c(va_list *args, t_prtf *struc)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (struc->width < 0)
	{
		struc->pad = 1;
		struc->width = struc->width * -1;
	}
	if (struc->pad)
	{
		ft_putchar(c, struc);
		ft_fill(' ', struc->width - 1, struc);
	}
	else if (!struc->pad && !struc->zero)
	{
		ft_fill(' ', struc->width - 1, struc);
		ft_putchar(c, struc);
	}
	else if (struc->zero)
	{
		ft_fill('0', struc->width - 1, struc);
		ft_putchar(c, struc);
	}
	else
		ft_putchar(c, struc);
}
