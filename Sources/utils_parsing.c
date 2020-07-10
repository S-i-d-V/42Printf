/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:30:32 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/10 15:41:29 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

#include "../Include/ft_printf.h"

void		ft_parse_pad(char c, t_prtf *struc, t_flags *flags)
{
	printf("ft_parse_pad : format[%d] = %c\n", struc->i, c); //Temporaire
	flags->pad = (c == '-' ? 1 : 0);
	if (flags->pad)
	{
		flags->fill  = ' ';
		struc->i++;
	}
}

void		ft_parse_zero(char c, t_prtf *struc, t_flags *flags)
{
	printf("ft_parse_zero : format[%d] = %c\n", struc->i, c); //Temporaire
	flags->zero = (c == '0' ? 1 : 0);
	if (flags->zero)
	{
		flags->fill  = '0';
		struc->i++;
	}
}

void		ft_parse_dot(const char *format, t_prtf *struc, t_flags *flags, va_list *args)
{
	printf("ft_parse_dot : format[%d] = %c | %s\n", struc->i, format[struc->i], format); //Temporaire
	if (format[struc->i] == '.')
	{
		struc->i++;
		flags->dot = 1;
		ft_parse_width(format, struc, flags, args);
	}
}

void		ft_parse_width(const char *format, t_prtf *struc, t_flags *flags, va_list *args)
{
	printf("ft_parse_width : format[%d] = %c | %s\n", struc->i, format[struc->i], format); //Temporaire
	if (format[struc->i] == '*')
	{
		flags->width = va_arg(*args, int);
		struc->i++;
	}
	else
	{
		while (ft_isdigit(format[struc->i]))
		{
			flags->width = flags->width * 10 + format[struc->i] - 48;
			struc->i++;
			printf("2: WIDTH = %d | format[%d] = %c\n", flags->width, struc->i, format[struc->i]); //Temporaire
		}
	}
}

void		ft_parse(const char *format, t_prtf *struc, t_flags *flags, va_list *args)
{
	innit_flags(flags);
	printf("ft_parse avant boucle: format[%d] = %c | %s\n", struc->i, format[struc->i], format); //Temporaire
	while (ft_checktype(format[struc->i]) == -1)
	{
		printf("Dans boucle avant if\n"); //Temporaire
		ft_parse_pad(format[struc->i], struc, flags);
		ft_parse_zero(format[struc->i], struc, flags);
		ft_parse_dot(format, struc, flags, args);
		ft_parse_width(format, struc, flags, args);
		if (ft_checktype(format[struc->i]))
			break;
		printf("Dans boucle avant if\n"); //Temporaire
	}
	printf("ft_parse apres boucle: format[%d] = %c | %s\n", struc->i, format[struc->i], format); //Temporaire
	flags->type = format[struc->i];
	ft_getfill(flags);
	ft_print_struc(*flags); //Temporaire
}

void		ft_getfill(t_flags *flags)
{
	if (flags->type == 'd' && (flags->dot || flags->zero))
		flags->fill = '0';
	else
		flags->fill = ' ';
	if (flags->pad)
		flags->side = 0;
	else
		flags->side = 1;
	if (flags->pad || flags->dot)
		flags->zero = 0;
}