/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:30:17 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 02:19:00 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void				ft_x(va_list *args, t_prtf *struc)
{
	unsigned int	n;
	char			*s;

	n = va_arg(*args, unsigned int);
	if (struc->prec < 0)
	{
		struc->prec = 1;
		struc->precisneg = 1;
	}
	s = ft_itoa_hexa(n, "0123456789abcdef");
	struc->len = ft_strlen(s);
	ft_display_x(s, struc);
	free(s);
	s = NULL;
}

void				ft_print_x(char *s, char fill, int side, t_prtf *struc)
{
	if (side)
	{
		if (struc->dot)
		{
			ft_fill(fill, struc->width - struc->prec, struc);
			ft_fill('0', struc->prec - struc->len, struc);
		}
		else
			ft_fill(fill, struc->width - struc->len, struc);
		ft_strto(s, struc->len, struc);
	}
	else
	{
		if (struc->dot)
			ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(s, struc->len, struc);
		if (struc->dot)
			ft_fill(fill, struc->width - struc->prec, struc);
		else
			ft_fill(fill, struc->width - struc->len, struc);
	}
}

void				ft_print_x_zero(char *s, t_prtf *struc)
{
	if (struc->dot)
	{
		if (!struc->precisneg)
		{
			ft_fill(' ', struc->width - struc->prec, struc);
			ft_fill('0', struc->prec - struc->len, struc);
		}
		if (struc->precisneg)
		{
			ft_fill('0', struc->width - struc->prec, struc);
			ft_fill(' ', struc->prec - struc->len, struc);
		}
		ft_strto(s, struc->len, struc);
	}
	else
	{
		ft_fill('0', struc->width - struc->len, struc);
		ft_strto(s, struc->len, struc);
	}
}

void				ft_display_x(char *s, t_prtf *struc)
{
	if (struc->width < 0)
	{
		struc->pad = 1;
		struc->width = struc->width * -1;
	}
	if (struc->dot && struc->prec == 0 && ft_atoi(s) == 0)
		struc->len = struc->prec;
	else if (struc->dot && struc->prec < struc->len)
		struc->prec = struc->len;
	if (struc->pad)
		ft_print_uint(s, ' ', 0, struc);
	else if (struc->zero)
		ft_print_uint_zero(s, struc);
	else if (!struc->pad && !struc->zero && struc->width)
		ft_print_uint(s, ' ', 1, struc);
	else
	{
		if (struc->dot)
			ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(s, struc->len, struc);
	}
}
