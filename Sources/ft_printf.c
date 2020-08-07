/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/07 15:37:01 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"
#include <stdio.h>

void	ft_print_struc(t_prtf struc)
{
	printf("PRINT STRUC :\n");
	printf("DOT	= '%d'\n", struc.dot);
	printf("PAD	= '%d'\n", struc.pad);
	printf("ZERO = '%d'\n", struc.zero);
	printf("SIDE = '%d'\n", struc.side);
	printf("WIDTH = '%d'\n", struc.width);
	printf("FILL = '%c'\n", struc.fill);
	printf("TYPE = '%c'\n", struc.type);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_prtf	struc;

	innit_struct(&struc);
	va_start(args, format);
	while (format[struc.i])
	{
		if (format[struc.i] == '%')
		{
			struc.i++;
			ft_parse(format, &struc, &args);
			ft_print_specifier(format, &args, &struc);
		}
		else
			ft_putchar(format[struc.i], &struc);
		struc.i++;
	}
	va_end(args);
	return (struc.ret);
}
