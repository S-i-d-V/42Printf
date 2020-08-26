/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:29:55 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 01:41:01 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void				ft_u(va_list *args, t_prtf *struc)
{
	unsigned int	n;
	char			*s;

	n = va_arg(*args, unsigned int);
	if (struc->prec < 0)
	{
		struc->prec = 1;
		struc->precisneg = 1;
	}
	s = ft_uitoa(n);
	struc->len = ft_strlen(s);
	ft_display_uint(s, struc);
	free(s);
	s = NULL;
}

void				ft_print_uint(char *s, char fill, int side, t_prtf *struc)
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

void				ft_print_uint_zero(char *s, t_prtf *struc)
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

void				ft_display_uint(char *s, t_prtf *struc)
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
