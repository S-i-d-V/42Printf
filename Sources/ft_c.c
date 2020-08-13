/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:08 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/13 14:21:27 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_c(va_list *args, t_prtf *struc)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (struc->side && struc->fill == ' ' && !struc->dot)
		width_c(c, struc);
	else if (!struc->side && struc->fill == ' ')
		pad_c(c, struc);
	else if (struc->side && struc->fill == '0')
		zero_c(c, struc);
	else if (struc->dot)
		ft_putchar(c, struc);
}

void	width_c(char c, t_prtf *struc)
{
	if (struc->width)
	{
		ft_fill(' ', (struc->width - 1), struc);
		ft_putchar(c, struc);
	}
	else
		ft_putchar(c, struc);
}

void	pad_c(char c, t_prtf *struc)
{
	if (struc->width)
	{
		ft_putchar(c, struc);
		ft_fill(' ', (struc->width - 1), struc);
	}
	else
		ft_putchar(c, struc);
}

void	zero_c(char c, t_prtf *struc)
{
	if (struc->width)
	{
		ft_fill('0', (struc->width - 1), struc);
		ft_putchar(c, struc);
	}
	else
		ft_putchar(c, struc);
}