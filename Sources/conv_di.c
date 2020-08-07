/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:11 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/07 15:35:00 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_d(va_list *args, t_prtf *struc)
{
	int n;
	char *str;
	
	n = va_arg(*args, int);
	str = ft_itoa(n);
	struc->neg = (n < 0) ? 1 : 0;
	struc->len = ft_strlen(str);
	if (struc->dot && struc->side == 1)
		dot_d(str, struc);
	else if (struc->pad && struc->side == 0)
		pad_d(str, struc);
	else if (!struc->pad && !struc-> dot && !struc->zero)
		width_d(str, struc);
	else if (struc->zero)
		zero_d(str, struc);
	free(str);
}

void	dot_d(char *str, t_prtf *struc)
{
	if (struc->len < struc->width && struc->neg)
	{
		str++;
		ft_putchar('-', struc);
		ft_fill('0', (struc->width - struc->len + 1), struc);
		ft_putstr(str, struc);
	}
	else if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}

void	pad_d(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_putstr(str, struc);
		ft_fill(' ', (struc->width - struc->len), struc);
	}
	else
		ft_putstr(str, struc);
}

void	width_d(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill(' ', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}

void	zero_d(char *str, t_prtf *struc)
{
	if (struc->len < struc->width && struc->neg)
	{
		str++;
		ft_putchar('-', struc);
		ft_fill('0', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}