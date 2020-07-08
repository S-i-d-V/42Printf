/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 01:16:44 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

t_tab		g_tab[9] = {
	{'c', &conv_c}, {'s', &conv_s}, {'p', &conv_p},
	{'d', &conv_d}, {'i', &conv_i}, {'u', &conv_u},
	{'x', &conv_x}, {'X', &conv_xx}, {'%', &conv_prc}
};

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
			g_tab[ft_checktype(format[struc.i])].tabFunc(&args, &struc);
		}
		else
			ft_putchar(format[struc.i], &struc);
		struc.i++;
	}
	va_end(args);
	return (struc.ret);
}