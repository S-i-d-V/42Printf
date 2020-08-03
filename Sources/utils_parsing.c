/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:30:32 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/03 15:39:52 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

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

void		ft_parse_dot(const char *format, t_prtf *struc, va_list *args)
{
	if (format[struc->i] == '.')
	{
		struc->i++;
		struc->dot = 1;
		ft_parse_width(format, struc, args);
	}
}

void		ft_parse_width(const char *format, t_prtf *struc, va_list *args)
{
	if (format[struc->i] == '*')
	{
		struc->width = va_arg(*args, int);
		struc->i++;
	}
	else
	{
		while (ft_isdigit(format[struc->i]))
		{
			struc->width = struc->width * 10 + format[struc->i] - 48;
			struc->i++;
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
		ft_parse_dot(format, struc, args);
		ft_parse_width(format, struc, args);
		if (ft_checktype(format[struc->i]))
			break;
	}
	struc->type = format[struc->i];
	ft_getfill(struc);
	//ft_print_struc(*struc); //Temporaire
}