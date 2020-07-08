/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/08 11:36:46 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	void (*tabFunc[9]) (va_list *, t_prtf *) =  {conv_c, conv_s, conv_p, conv_d, conv_i, conv_u, conv_x, conv_xx, conv_prc};
	va_list args;
	t_prtf struc;

	innit_struct(&struc);
	va_start(args, format);
	while (format[struc.i])
	{
		if (format[struc.i] == '%')
		{
			struc.i++;
			(*tabFunc[ft_checktype(format[struc.i])]) (&args, &struc);
		}
		else
			ft_putchar(format[struc.i], &struc);
		struc.i++;
	}
	va_end(args);
	return (struc.ret);
}
