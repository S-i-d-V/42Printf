/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:51:48 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/10 14:22:58 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_p(va_list *args, t_prtf *struc)
{
	unsigned long long n;
	char *str;
	
	n = va_arg(*args, unsigned long long);
	str = ft_ltoa_hexa(n, "0123456789abcdef");
	struc->len = ft_strlen(str);
	if (struc->dot && struc->side == 1)
		dot_p(str, struc);
	else if (struc->pad && struc->side == 0)
		pad_p(str, struc);
	else if (!struc->pad && !struc-> dot && !struc->zero)
		width_p(str, struc);
	else if (struc->zero)
		zero_p(str, struc);
	free(str);
}

void	dot_p(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len + 2), struc);
		ft_putstr("0x", struc);
		ft_putstr(str, struc);
	}
	else
	{
		ft_putstr("0x", struc);
		ft_putstr(str, struc);
	}
}

void	pad_p(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_putstr("0x", struc);
		ft_putstr(str, struc);
		ft_fill(' ', (struc->width - struc->len + 2), struc);
	}
	else
	{
		ft_putstr("0x", struc);
		ft_putstr(str, struc);
	}
}

void	width_p(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill(' ', (struc->width - struc->len + 2), struc);
		ft_putstr("0x", struc);
		ft_putstr(str, struc);
	}
	else
	{
		ft_putstr("0x", struc);
		ft_putstr(str, struc);
	}
}

void	zero_p(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len + 2), struc);
		ft_putstr("0x", struc);
		ft_putstr(str, struc);
	}
	else
	{
		ft_putstr("0x", struc);
		ft_putstr(str, struc);
	}
}