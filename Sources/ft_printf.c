/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:17:58 by ugtheven          #+#    #+#             */
/*   Updated: 2020/06/30 12:13:12 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/ft_printf.h"

int		ft_checkflag(char c)
{
	char *flags;
	int i = 0;
	
	flags = "cspdiuxX%";
	while (flags[i])
	{
		if (flags[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	void (*TabFunc[9]) (va_list *) =  {flag_c, flag_s, flag_p, flag_d, flag_i, flag_u, flag_x, flag_xx, flag_prc};
	char tabIndex[10] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%', 0};
	va_list list;
	int i;
	int tmpIndex;

	i = 0;
	tmpIndex = 0;
	va_start(args, format);
	while (format[i])
	{
		if (i != 0 && src[i - 1] == '%')
		{
			tmpIndex = ft_checkflag(format[i]);
			if (tmpIndex != -1)
				(*tabFunc[tmpIndex]) (&my_list);
		}
		else if
			write(1, %src[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}

int 	main()
{
	ft_printf("%c %s %d %i %u %x %X\n", 'c', "string", 42, -5, -5, 5642);
}
