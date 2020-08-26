/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:46:35 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 01:38:28 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_parse_zero(char *format, t_prtf *struc, va_list *args)
{
	struc->zero = 1;
	struc->i++;
	if (format[struc->i] == '*')
	{
		struc->width = va_arg(*args, int);
		struc->i++;
	}
	while (ft_isdigit(format[struc->i]))
	{
		struc->width = struc->width * 10 + (format[struc->i] - 48);
		struc->i++;
	}
}

void		ft_parse_dot(char *format, t_prtf *struc, va_list *args)
{
	struc->dot = 1;
	struc->i++;
	if (format[struc->i] == '*')
	{
		struc->prec = va_arg(*args, int);
		struc->i++;
	}
	while (ft_isdigit(format[struc->i]))
	{
		struc->prec = struc->prec * 10 + (format[struc->i] - 48);
		struc->i++;
	}
}

void		ft_parse_pad(char *format, t_prtf *struc, va_list *args)
{
	struc->pad = 1;
	struc->zero = 0;
	struc->i++;
	if (format[struc->i] == '*')
	{
		struc->width = va_arg(*args, int);
		struc->i++;
	}
	while (ft_isdigit(format[struc->i]))
	{
		struc->width = struc->width * 10 + (format[struc->i] - 48);
		struc->i++;
	}
}

void		ft_parse_width(char *format, t_prtf *struc, va_list *args)
{
	if (format[struc->i] == '*')
	{
		struc->width = va_arg(*args, int);
		struc->i++;
	}
	while (ft_isdigit(format[struc->i]))
	{
		struc->width = struc->width * 10 + (format[struc->i] - 48);
		struc->i++;
	}
}

void		ft_parse(char *format, t_prtf *struc, va_list *args)
{
	reset_flags(struc);
	while (format[struc->i])
	{
		if (ft_err_parse(format, struc->i) == -1)
			break ;
		if (format[struc->i] == '0' && !struc->width)
			ft_parse_zero(format, struc, args);
		if (!ft_isdigit(format[struc->i]) && ft_isflags(format[struc->i]) < 0)
			break ;
		if (format[struc->i] == '*' || ft_isdigit(format[struc->i]))
			ft_parse_width(format, struc, args);
		if (format[struc->i] == '-')
			ft_parse_pad(format, struc, args);
		if (format[struc->i] == '.')
			ft_parse_dot(format, struc, args);
		if (ft_istypes(format[struc->i]) >= 0)
			break ;
		struc->i++;
	}
}
