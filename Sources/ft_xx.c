/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:30:37 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/19 15:51:17 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void				ft_xx(va_list *args, t_prtf *struc)
{
	unsigned int	n;
	char			*str;

	n = va_arg(*args, unsigned int);
	str = ft_itoa_hexa(n, "0123456789ABCDEF");
	struc->len = ft_strlen(str);
	ft_display_xxint(str, struc);
	free(str);
}

void		ft_display_xxint(char *str, t_prtf *struc)
{
	if (struc->pad)
	{
		if (struc->dot)
		{
			if (struc->prec > struc->len)
			{
				ft_fill('0', struc->prec - struc->len, struc);
				ft_strto(str, struc->len, struc);
				ft_fill(' ', struc->width - struc->prec, struc);
			}
			else
			{
				if (struc->prec == 0)
				{
					struc->len = struc->prec;
					struc->width++;
				}
				ft_fill('0', struc->prec - struc->len, struc);
				ft_strto(str, struc->len, struc);
				ft_fill(' ', struc->width - struc->prec - 1, struc);
			}
		}
		else
		{
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->len, struc);
		}
	}
	else if (struc->zero && !struc->dot)
	{
		ft_fill('0', struc->width - struc->len, struc);
		ft_strto(str, struc->len, struc);
	}
	else if (!struc->pad && struc->width)
	{
		if (struc->dot)
		{
			if (struc->prec == 0)
				struc->len = struc->prec;
			if (struc->prec > struc->len)
			{
				ft_fill(' ', struc->width - struc->prec, struc);
				ft_fill('0', struc->prec - struc->len, struc);
				ft_strto(str, struc->len, struc);
			}
			else
			{
				ft_fill(' ', struc->width - struc->len, struc);
				ft_fill('0', struc->prec - struc->len, struc);
				ft_strto(str, struc->len, struc);
			}
		}
		else
		{
			ft_fill(' ', struc->width - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (struc->dot)
	{
		if (struc->prec == 0)
			struc->len = struc->prec;
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(str, struc->len, struc);
	}
	else
		ft_strto(str, struc->len, struc);
}
