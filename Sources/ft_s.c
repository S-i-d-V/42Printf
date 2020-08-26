/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:55 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 02:20:42 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_s(va_list *args, t_prtf *struc)
{
	char	*s;

	s = va_arg(*args, char *);
	if (s == NULL)
		s = "(null)";
	struc->len = ft_strlen(s);
	ft_display_s(s, struc);
}

void		ft_print_s(char *s, char fill, int side, t_prtf *struc)
{
	if (struc->dot)
	{
		if (side && struc->prec > struc->len)
			ft_fill(fill, struc->width - struc->len, struc);
		else if (side)
			ft_fill(fill, struc->width - struc->prec, struc);
		ft_strto(s, struc->prec, struc);
		if (!side && struc->prec > struc->len)
			ft_fill(fill, struc->width - struc->len, struc);
		else if (!side)
			ft_fill(fill, struc->width - struc->prec, struc);
	}
	else
	{
		if (side)
			ft_fill(fill, struc->width - struc->len, struc);
		ft_strto(s, struc->len, struc);
		if (!side)
			ft_fill(fill, struc->width - struc->len, struc);
	}
}

void		ft_display_s(char *s, t_prtf *struc)
{
	if (struc->width < 0)
	{
		struc->pad = 1;
		struc->width = struc->width * -1;
	}
	if (struc->prec < 0)
		struc->prec = struc->len;
	if (struc->pad)
		ft_print_s(s, ' ', 0, struc);
	else if (struc->zero)
		ft_print_s(s, '0', 1, struc);
	else if (!struc->pad && struc->width)
		ft_print_s(s, ' ', 1, struc);
	else if (struc->dot)
		ft_strto(s, struc->prec, struc);
	else
		ft_strto(s, struc->len, struc);
}
