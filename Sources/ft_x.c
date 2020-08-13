/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:30:17 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/13 12:30:42 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void				ft_x(va_list *args, t_prtf *struc)
{
	unsigned int	n;
	char			*str;

	n = va_arg(*args, unsigned int);
	str = ft_itoa_hexa(n, "0123456789abcdef");
	struc->len = ft_strlen(str);
	if (struc->dot && struc->side == 1)
		dot_x(str, struc);
	else if (struc->pad && struc->side == 0)
		pad_x(str, struc);
	else if (!struc->pad && !struc->dot && !struc->zero)
		width_x(str, struc);
	else if (struc->zero)
		zero_x(str, struc);
	free(str);
}

void				dot_x(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}

void				pad_x(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_putstr(str, struc);
		ft_fill(' ', (struc->width - struc->len), struc);
	}
	else
		ft_putstr(str, struc);
}

void				width_x(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill(' ', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}

void				zero_x(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}
