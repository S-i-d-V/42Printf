/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:29:55 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/13 12:30:00 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void				ft_u(va_list *args, t_prtf *struc)
{
	unsigned int	n;
	char			*str;

	n = va_arg(*args, unsigned int);
	str = ft_uitoa(n);
	struc->len = ft_strlen(str);
	if (struc->dot && struc->side == 1)
		dot_u(str, struc);
	else if (struc->pad && struc->side == 0)
		pad_u(str, struc);
	else if (!struc->pad && !struc->dot && !struc->zero)
		width_u(str, struc);
	else if (struc->zero)
		zero_u(str, struc);
	free(str);
}

void				dot_u(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}

void				pad_u(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_putstr(str, struc);
		ft_fill(' ', (struc->width - struc->len), struc);
	}
	else
		ft_putstr(str, struc);
}

void				width_u(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill(' ', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}

void				zero_u(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len), struc);
		ft_putstr(str, struc);
	}
	else
		ft_putstr(str, struc);
}
