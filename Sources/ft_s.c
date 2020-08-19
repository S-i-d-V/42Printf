/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:55 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/19 12:32:30 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_s(va_list *args, t_prtf *struc)
{
	char	*str;

	str = va_arg(*args, char *);
	struc->len = ft_strlen(str);
	ft_display_string(str, struc);
}

void		ft_display_string(char *str, t_prtf *struc)
{
	if (struc->pad)
	{
		if (struc->dot)
		{
			ft_strto(str, struc->prec, struc);
			ft_fill(' ', struc->width - struc->prec, struc);
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
			ft_fill('0', struc->width - struc->prec, struc);
			ft_strto(str, struc->prec, struc);
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
			ft_fill(' ', struc->width - struc->prec, struc);
			ft_strto(str, struc->prec, struc);
		}
		else
		{
			ft_fill(' ', struc->width - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (struc->dot)
		ft_strto(str, struc->prec, struc);
	else
		ft_strto(str, struc->len, struc);
}
