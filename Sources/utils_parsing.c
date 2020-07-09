/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:30:32 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 16:51:12 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_parse_pad(char c, t_prtf *struc, t_flags *flags)
{
	flags->pad = (c == '-' ? 1 : 0);
	if (flags->pad)
	{
		flags->fill  = ' ';
		struc->i++;
	}
}

void		ft_parse_zero(char c, t_prtf *struc, t_flags *flags)
{
	flags->zero = (c == '0' ? 1 : 0);
	if (flags->zero)
	{
		flags->fill  = '0';
		struc->i++;
	}
}

void		ft_parse_precision(const char *format, t_prtf *struc, t_flags *flags, va_list *args)
{
	if (format[struc->i] == '.')
	{
		struc->i++;
		if (format[struc->i] == '*')
			flags->width = va_arg(*args, int);
		else
		{
			while (ft_isdigit(format[struc->i]))
			{
				flags->width = flags->width * 10 + format[struc->i];
				struc->i++;
			}
		}
	}
}

void		ft_parse(const char *format, t_prtf *struc, t_flags *flags, va_list *args)
{
	innit_flags(flags);
	while (ft_checktype(format[struc->i]) == -1)
	{
		ft_parse_pad(format[struc->i], struc, flags);
		ft_parse_zero(format[struc->i], struc, flags);
		ft_parse_precision(format, struc, flags, args);
	}
}