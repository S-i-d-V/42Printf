/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:30:32 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 01:16:44 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_parse_pad(char c, t_prtf *struc)
{
	struc->pad = (c == '-' ? 1 : 0);
	if (struc->pad)
	{
		struc->fill  = ' ';
		struc->i++;
	}
}

void		ft_parse_zero(char c, t_prtf *struc)
{
	struc->zero = (c == '0' ? 1 : 0);
	if (struc->zero)
	{
		struc->fill  = '0';
		struc->i++;
	}
}

void		ft_parse_precision(const char *format, t_prtf *struc, va_list *args)
{
	if (format[struc->i] == '.')
	{
		struc->i++;
		if (format[struc->i] == '*')
			struc->prec = va_arg(*args, int);
		else
		{
			while (ft_isdigit(format[struc->i]))
			{
				struc->prec = struc->prec * 10 + format[struc->i];
				struc->i++;
			}
		}
	}
}

void		ft_parse(const char *format, t_prtf *struc, va_list *args)
{
	reset_flags(struc);
	while (ft_checktype(format[struc->i]) == -1)
	{
		ft_parse_pad(format[struc->i], struc);
		ft_parse_zero(format[struc->i], struc);
		ft_parse_precision(format, struc, args);
	}
}