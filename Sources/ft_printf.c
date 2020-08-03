/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/03 10:32:55 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"
#include <stdio.h>

void	ft_print_struc(t_flags flags)
{
	printf("PRINT STRUC :\n");
	printf("DOT	= '%d'\n", flags.dot);
	printf("PAD	= '%d'\n", flags.pad);
	printf("ZERO = '%d'\n", flags.zero);
	printf("SIDE = '%d'\n", flags.side);
	printf("WIDTH = '%d'\n", flags.width);
	printf("FILL = '%c'\n", flags.fill);
	printf("TYPE = '%c'\n", flags.type);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_prtf	struc;
	t_flags flags;

	innit_struct(&struc);
	va_start(args, format);
	printf("============================\n"); //Temporaire
	while (format[struc.i])
	{
		if (format[struc.i] == '%')
		{
			struc.i++;
			ft_parse(format, &struc, &flags, &args);
			ft_print_specifier(format, &args, &struc, &flags);
		}
		else
			ft_putchar(format[struc.i], &struc);
		struc.i++;
	}
	printf("============================\n"); //Temporaire
	va_end(args);
	return (struc.ret);
}
