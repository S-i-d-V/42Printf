/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:31:25 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 02:30:30 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void					ft_p(va_list *args, t_prtf *struc)
{
	unsigned long long	n;
	char				*s;

	n = va_arg(*args, unsigned long long);
	if (n)
		s = ft_itoa_hexa(n, "0123456789abcdef");
	else if (!n && struc->dot)
		s = ft_strdup("");
	else
		s = ft_strdup("0");
	struc->len = ft_strlen(s);
	ft_display_p(s, struc);
	free(s);
}

void					ft_print_p(char *s, char fill, int side, t_prtf *struc)
{
	if (side)
	{
		if (struc->dot && struc->len < struc->prec)
			ft_fill(fill, struc->width - struc->prec, struc);
		else
			ft_fill(fill, struc->width - (struc->len + 2), struc);
		ft_strto("0x", 2, struc);
		if (struc->dot && struc->len < struc->prec)
			ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(s, struc->len, struc);
	}
	else
	{
		if (struc->dot && struc->len < struc->prec)
			ft_fill('0', struc->prec - struc->len, struc);
		ft_strto("0x", 2, struc);
		ft_strto(s, struc->len, struc);
		if (struc->dot && struc->len < struc->prec)
			ft_fill(fill, struc->width - struc->prec, struc);
		else
			ft_fill(fill, struc->width - (struc->len + 2), struc);
	}
}

void					ft_print_p_width(char *s, t_prtf *struc)
{
	if (struc->dot && struc->len < struc->prec)
		ft_print_p(s, '0', 1, struc);
	else
	{
		if (struc->len == 0)
		{
			if (struc->dot)
				ft_print_p(s, ' ', 1, struc);
			else
			{
				ft_fill(' ', struc->width - (struc->len + 3), struc);
				ft_strto("0x", 2, struc);
				ft_putchar('0', struc);
			}
		}
		else
			ft_print_p(s, ' ', 1, struc);
	}
}

void					ft_display_p(char *s, t_prtf *struc)
{
	if (struc->pad)
		ft_print_p(s, ' ', 0, struc);
	else if (struc->zero)
		ft_print_p(s, ' ', 1, struc);
	else if (!struc->pad && struc->width)
		ft_print_p_width(s, struc);
	else if (struc->dot)
	{
		ft_strto("0x", 2, struc);
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(s, struc->len, struc);
	}
	else
	{
		ft_strto("0x", 2, struc);
		if (s[0] == '\0')
			ft_putchar('0', struc);
		else
			ft_strto(s, struc->len, struc);
	}
}
