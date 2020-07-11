/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/10 16:45:02 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"
#include <stdio.h>

t_tab		g_tab[9] = {
	{'c', &conv_c}, {'s', &conv_s}, {'p', &conv_p},
	{'d', &conv_d}, {'i', &conv_i}, {'u', &conv_u},
	{'x', &conv_x}, {'X', &conv_xx}, {'%', &conv_prc}
};

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
			printf("ft_printf : format[%d] = %c | %s\n", struc.i, format[struc.i], format); //Temporaire
			struc.i++;
			printf("ft_printf : format[%d] = %c | %s\n", struc.i, format[struc.i], format); //Temporaire
			ft_parse(format, &struc, &flags, &args);
			//ft_print_specifier
			g_tab[ft_checktype(format[struc.i])].tabFunc(&args, &struc, &flags);
		}
		else
			ft_putchar(format[struc.i], &struc);
		struc.i++;
	}
	printf("============================\n"); //Temporaire
	va_end(args);
	return (struc.ret);
}
