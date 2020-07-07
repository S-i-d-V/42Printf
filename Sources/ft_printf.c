/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/07 16:29:48 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	void (*tabFunc[9]) (va_list *, t_ptrf *) =  {flag_c, flag_s, flag_p, flag_d, flag_i, flag_u, flag_x, flag_xx, flag_prc};
	va_list args;
	t_ptrf struc;
	int i;
	int tmpIndex;

	i = 0;
	tmpIndex = 0;
	innit_struct(&struc);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			tmpIndex = ft_checkflag(format[i]);
			if (tmpIndex != -1)
				(*tabFunc[tmpIndex]) (&args, &struc);
		}
		else
			ft_putchar(format[i], &struc);
		i++;
	}
	va_end(args);
	return (struc.ret);
}
