/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:31:25 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/19 12:03:27 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void					ft_p(va_list *args, t_prtf *struc)
{
	unsigned long long	n;
	char				*str;

	n = va_arg(*args, unsigned long long);
	str = ft_ltoa_hexa(n, "0123456789abcdef");
	struc->len = ft_strlen(str);
	ft_display_pointer(str, struc);
	free(str);
}

void		ft_display_pointer(char *str, t_prtf *struc)
{
	if (struc->pad)
	{
		if (struc->dot && struc->len < struc->prec)
		{
			ft_fill('0', struc->prec - struc->len, struc);
			ft_strto("0x", 2, struc);
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->prec, struc);
		}
		else
		{
			ft_strto("0x", 2, struc);
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - (struc->len + 2), struc);
		}
	}
	else if (struc->zero)
	{
		if (struc->dot && struc->len < struc->prec)
		{
			ft_fill(' ', struc->width - struc->prec, struc);
			ft_strto("0x", 2, struc);
			ft_fill('0', struc->prec - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
		else
		{
			ft_fill(' ', struc->width - (struc->len + 2), struc);
			ft_strto("0x", 2, struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (!struc->pad && struc->width)
	{
		if (struc->dot && struc->len < struc->prec)
		{
			ft_fill('0', struc->width - struc->prec, struc);
			ft_strto("0x", 2, struc);
			ft_fill('0', struc->prec - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
		else
		{
			ft_fill(' ', struc->width - (struc->len + 2), struc);
			ft_strto("0x", 2, struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (struc->dot)
	{
		ft_strto("0x", 2, struc);
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(str, struc->len, struc);
	}
	else
	{
		ft_strto("0x", 2, struc);
		ft_strto(str, struc->len, struc);
	}
}
