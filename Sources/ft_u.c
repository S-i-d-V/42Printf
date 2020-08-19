/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:29:55 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/19 10:53:20 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void				ft_u(va_list *args, t_prtf *struc)
{
	unsigned int	n;
	char			*str;

	n = va_arg(*args, unsigned int);
	str = ft_uitoa(n);
	struc->len = ft_strlen(str);
	ft_display_uint(str, struc);
	free(str);
}

void		ft_display_uint(char *str, t_prtf *struc)
{
	if (struc->pad)
	{
		if (struc->dot)
		{
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->len, struc);
		}
		else
		{
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->len, struc);
		}
	}
	else if (struc->zero)
	{
		if (struc->dot)
		{
			ft_fill(' ', struc->width - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
		else
		{
			ft_fill('0', struc->width - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (!struc->pad && struc->width)
	{
		if (struc->dot)
		{
			ft_fill('0', struc->width - struc->prec, struc);
			ft_fill('0', struc->prec - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
		else
		{
			ft_fill(' ', struc->width - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (struc->dot)
	{
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(str, struc->len, struc);
	}
	else
		ft_strto(str, struc->len, struc);
}
