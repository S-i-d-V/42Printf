/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:30:37 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/25 14:34:18 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void				ft_xx(va_list *args, t_prtf *struc)
{
	unsigned int	n;
	char			*str;

	n = va_arg(*args, unsigned int);
	if (struc->prec < 0)
	{
		struc->prec = 1;
		struc->precisneg = 1;
	}
	str = ft_itoa_hexa(n, "0123456789ABCDEF");
	struc->len = ft_strlen(str);
	ft_display_xint(str, struc);
	free(str);
	str = NULL;
}

void				ft_display_xxint(char *str, t_prtf *struc)
{
	if (struc->width < 0)
	{
		struc->pad = 1;
		struc->width = struc->width * -1;
	}
	if (struc->dot && struc->prec == 0 && ft_atoi(str) == 0)
		struc->len = struc->prec;
	else if (struc->dot && struc->prec < struc->len)
		struc->prec = struc->len;
	if (struc->pad)
	{
		if (struc->dot)
		{
			ft_fill('0', struc->prec - struc->len, struc);
			ft_strto(str, struc->len, struc);
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
			if (struc->precisneg)
			{
				ft_fill('0', struc->width - struc->prec - struc->neg, struc);
				ft_fill(' ', struc->prec - struc->len, struc);
				ft_strto(str, struc->len, struc);
			}
			else
			{
				ft_fill(' ', struc->width - struc->prec - struc->neg, struc);
				ft_fill('0', struc->prec - struc->len, struc);
				ft_strto(str, struc->len, struc);
			}
		}
		else
		{
			ft_fill('0', struc->width - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (!struc->pad && !struc->zero && struc->width)
	{
		if (struc->dot)
		{
			ft_fill(' ', struc->width - struc->prec, struc);
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
		if (struc->prec == 0 && ft_atoi(str) == 0)
			struc->len = struc->prec;
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(str, struc->len, struc);
	}
	else
		ft_strto(str, struc->len, struc);
}
