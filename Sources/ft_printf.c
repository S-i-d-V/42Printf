/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 16:03:10 by ugtheven         ###   ########.fr       */
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
	t_flags flags;

	innit_struct(&struc);
	va_start(args, format);
	while (format[struc.i])
	{
		if (format[struc.i] == '%')
		{
			struc.i++;
			//ft_parse(format, &struc, &flags, &args);		-> Reset la structure flags puis la remplis;
			//ft_print_format()								-> Recupere la structure puis print en fonction;
			g_tab[ft_checktype(format[struc.i])].tabFunc(&args, &struc, &flags);
		}
		else
			ft_putchar(format[struc.i], &struc);
		struc.i++;
	}
	va_end(args);
	return (struc.ret);
}