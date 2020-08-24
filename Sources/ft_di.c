/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/23 23:08:12 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	ft_d(va_list *args, t_prtf *struc)
{
	int		n;
	char	*str;

	n = va_arg(*args, int);
	if (n < 0)
		struc->neg = 1;
	str = ft_itoapos(n);
	struc->len = ft_strlen(str);
	ft_display_int(str, struc);
	free(str);
	str = NULL;
}

void		ft_display_int(char *str, t_prtf *struc)
{
	if (struc->width < 0)
	{
		struc->pad = 1;
		struc->width = struc->width * -1;
	}
	if (struc->dot && struc->prec == 0 && ft_atoi(str) == 0)
		struc->len = struc->prec;
	if (struc->dot && struc->prec < struc->len)
		struc->prec = struc->len;
	if (struc->pad)
	{
		if (struc->dot)
		{
			if (struc->neg)
				ft_putchar('-', struc);
			ft_fill('0', struc->prec - struc->len, struc);
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->prec - struc->neg, struc);
		}
		else
		{
			if (struc->neg)
				ft_putchar('-', struc);
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->len - struc->neg, struc);
		}
	}
	else if (struc->zero)
	{
		if (struc->dot)
		{
			ft_fill(' ', struc->width - struc->prec - struc->neg, struc);
			if (struc->neg)
				ft_putchar('-', struc);
			ft_fill('0', struc->prec - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
		else
		{
			if (struc->neg)
				ft_putchar('-', struc);
			ft_fill('0', struc->width - struc->len - struc->neg, struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (!struc->pad && !struc->zero && struc->width)
	{
		if (struc->dot)
		{
			ft_fill(' ', struc->width - struc->prec - struc->neg, struc);
			if (struc->neg)
				ft_putchar('-', struc);
			ft_fill('0', struc->prec - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
		else
		{
			ft_fill(' ', struc->width - struc->len - struc->neg, struc);
			if (struc->neg)
				ft_putchar('-', struc);
			ft_strto(str, struc->len, struc);
		}
	}
	else if (struc->dot)
	{
		if (struc->prec == 0 && ft_atoi(str) == 0)
				struc->len = struc->prec;
		if (struc->neg)
			ft_putchar('-', struc);
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(str, struc->len, struc);
	}
	else
	{
		if (struc->neg)
			ft_putchar('-', struc);
		ft_strto(str, struc->len, struc);
	}
}
