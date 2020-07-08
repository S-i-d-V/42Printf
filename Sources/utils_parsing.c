/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:30:32 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/08 13:32:22 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int			ft_checktype(char c)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "cspdiuxX%";
	while (flags[i])
	{
		if (flags[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_tab		g_tab[9] = {
	{'c', &conv_c}, {'s', &conv_s}, {'p', &conv_p},
	{'d', &conv_d}, {'i', &conv_i}, {'u', &conv_u},
	{'x', &conv_x}, {'X', &conv_xx}, {'%', &conv_prc}
};

void		ft_parse(const char *format, va_list *args, t_prtf *struc)
{
	while (format[struc->i])
	{
		if (format[struc->i] == '%')
		{
			struc->i++;
			g_tab[ft_checktype(format[struc->i])].tabFunc(args, struc);
		}
		else
			ft_putchar(format[struc->i], struc);
		struc->i++;
	}
}