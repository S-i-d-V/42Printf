/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:55 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/13 12:30:00 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_s(va_list *args, t_prtf *struc)
{
	char	*str;

	str = va_arg(*args, char *);
	struc->len = ft_strlen(str);
	if (struc->dot)
		ft_strto(str, struc->width, struc);
	else if (struc->pad && struc->side == 0)
		pad_s(str, struc);
	else if (!struc->pad && !struc->dot && !struc->zero)
		width_s(str, struc);
	else if (struc->zero)
		zero_s(str, struc);
}

void		pad_s(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_strto(str, struc->len, struc);
		ft_fill(' ', (struc->width - struc->len), struc);
	}
	else
		ft_putstr(str, struc);
}

void		width_s(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill(' ', (struc->width - struc->len), struc);
		ft_strto(str, struc->len, struc);
	}
	else
		ft_putstr(str, struc);
}

void		zero_s(char *str, t_prtf *struc)
{
	if (struc->len < struc->width)
	{
		ft_fill('0', (struc->width - struc->len), struc);
		ft_strto(str, struc->len, struc);
	}
	else
		ft_putstr(str, struc);
}
