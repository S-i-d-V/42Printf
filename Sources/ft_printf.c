/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:48 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/25 14:36:24 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"
#include <stdio.h>

t_tab		g_tab[9] = {
	{'c', &ft_c}, {'s', &ft_s}, {'p', &ft_p},
	{'d', &ft_d}, {'i', &ft_d}, {'u', &ft_u},
	{'x', &ft_x}, {'X', &ft_xx}, {'%', &ft_prc}
};

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_prtf	struc;

	innit_struct(&struc);
	va_start(args, format);
	while (format[struc.i])
	{
		if (format[struc.i] == '%' && format[struc.i + 1])
		{
			struc.i++;
			ft_parse((char *)format, &struc, &args);
			if (ft_istypes(format[struc.i]) != -1)
				g_tab[ft_istypes(format[struc.i])].tabfunc(&args, &struc);
		}
		else
			ft_putchar(format[struc.i], &struc);
		struc.i++;
	}
	va_end(args);
	return (struc.ret);
}
