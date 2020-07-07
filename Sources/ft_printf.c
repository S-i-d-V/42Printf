/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/07 13:39:34 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	void (*tabFunc[9]) (va_list *) =  {flag_c, flag_s, flag_p, flag_d, flag_i, flag_u, flag_x, flag_xx, flag_prc};
	va_list list;
	int i;
	int tmpIndex;

	i = 0;
	tmpIndex = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			tmpIndex = ft_checkflag(format[i]);
			if (tmpIndex != -1)
				(*tabFunc[tmpIndex]) (&list);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(list);
	return (i);
}
