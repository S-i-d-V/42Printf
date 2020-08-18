/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:55 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/18 23:19:16 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_s(va_list *args, t_prtf *struc)
{
	char	*str;

	str = va_arg(*args, char *);
	struc->len = ft_strlen(str);
	ft_display_string(str, struc);
}

void		ft_pad_string(char *str, t_prtf *struc)
{
	if (struc->dot)
		{
			ft_strto(str, struc->prec, struc);
			ft_fill(' ', struc->width - struc->prec, struc);
		}
		else
		{
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->len, struc);
		}
}

void		ft_dot_string(char *str, t_prtf *struc)
{
	if (struc->width)
	{
		ft_fill(' ', struc->width - struc->prec, struc);
		ft_strto(str, struc->prec, struc);
	}
	else
		ft_strto(str, struc->prec, struc);
}

void		ft_display_string(char *str, t_prtf *struc)
{
	if (struc->pad)
		ft_pad_string(str, struc);
	else if (struc->dot)
		ft_dot_string(str, struc);
	else if (!struc->pad && !struc->dot && struc->width)
	{
		ft_fill(' ', struc->width - struc->len, struc);
		ft_strto(str, struc->len, struc);
	}
	else
		ft_strto(str, struc->len, struc);
}