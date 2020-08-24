/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:46:35 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/23 18:41:59 by ugotheveny       ###   ########.fr       */
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

int			ft_err_parse(char *format, int i)
{
	int check;

	check = 0;
	while (format[i] && check != 1)
	{
		if (!ft_isdigit(format[i]) && ft_checkflags(format[i]) < 0)
		{
			if (ft_checktypes(format[i]) >= 0)
				check = 1;
			else
				return (-1);
		}
		else if (ft_checktypes(format[i]) >= 0)
		{
			check = 1;
			break;
		}
		else
			i++;
	}
	if (check == 1)
		return (1);
	else
		return (-1);
}

void		ft_parse(char *format, t_prtf *struc, va_list *args)
{
	reset_flags(struc);
	while (format[struc->i])
	{
		if (ft_err_parse(format, struc->i) == -1)
			break;
		if (format[struc->i] == '0' && !struc->width)
			ft_parse_zero(format, struc, args);
		if (!ft_isdigit(format[struc->i]) && ft_checkflags(format[struc->i]) < 0)
			break;
		if (format[struc->i] == '*' || ft_isdigit(format[struc->i]))
			ft_parse_width(format, struc, args);
		if (format[struc->i] == '-')
			ft_parse_pad(format, struc, args);
		if (format[struc->i] == '.')
			ft_parse_dot(format, struc, args);
		if (ft_checktypes(format[struc->i]) >= 0)
			break;
		struc->i++;
	}
}