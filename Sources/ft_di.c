/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 02:20:18 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_d(va_list *args, t_prtf *struc)
{
	int		n;
	char	*s;

	n = va_arg(*args, int);
	if (n < 0)
		struc->neg = 1;
	if (struc->prec < 0)
	{
		struc->prec = 1;
		struc->precisneg = 1;
	}
	s = ft_itoapos(n);
	struc->len = ft_strlen(s);
	ft_display_d(s, struc);
	free(s);
	s = NULL;
}

void		ft_print_d_pad(char *s, t_prtf *struc)
{
	if (struc->dot)
	{
		if (struc->neg)
			ft_putchar('-', struc);
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(s, struc->len, struc);
		ft_fill(' ', struc->width - struc->prec - struc->neg, struc);
	}
	else
	{
		if (struc->neg)
			ft_putchar('-', struc);
		ft_strto(s, struc->len, struc);
		ft_fill(' ', struc->width - struc->len - struc->neg, struc);
	}
}

void		ft_print_d_zero(char *s, t_prtf *struc)
{
	if (struc->dot)
	{
		if (!struc->precisneg)
			ft_fill(' ', struc->width - struc->prec - struc->neg, struc);
		if (struc->neg)
			ft_putchar('-', struc);
		if (!struc->precisneg)
			ft_fill('0', struc->prec - struc->len, struc);
		if (struc->precisneg)
		{
			ft_fill('0', struc->width - struc->prec - struc->neg, struc);
			ft_fill(' ', struc->prec - struc->len, struc);
		}
		ft_strto(s, struc->len, struc);
	}
	else
	{
		if (struc->neg)
			ft_putchar('-', struc);
		ft_fill('0', struc->width - struc->len - struc->neg, struc);
		ft_strto(s, struc->len, struc);
	}
}

void		ft_print_d_width(char *s, t_prtf *struc)
{
	if (struc->dot)
	{
		ft_fill(' ', struc->width - struc->prec - struc->neg, struc);
		if (struc->neg)
			ft_putchar('-', struc);
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(s, struc->len, struc);
	}
	else
	{
		ft_fill(' ', struc->width - struc->len - struc->neg, struc);
		if (struc->neg)
			ft_putchar('-', struc);
		ft_strto(s, struc->len, struc);
	}
}

void		ft_display_d(char *s, t_prtf *struc)
{
	if (struc->width < 0)
	{
		struc->pad = 1;
		struc->width = struc->width * -1;
	}
	if (struc->dot && struc->prec == 0 && ft_atoi(s) == 0)
		struc->len = 0;
	else if (struc->dot && struc->prec < struc->len)
		struc->prec = struc->len;
	if (struc->pad)
		ft_print_d_pad(s, struc);
	else if (struc->zero)
		ft_print_d_zero(s, struc);
	else if (!struc->pad && !struc->zero && struc->width)
		ft_print_d_width(s, struc);
	else
	{
		if (struc->neg)
			ft_putchar('-', struc);
		if (struc->dot)
			ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(s, struc->len, struc);
	}
}
