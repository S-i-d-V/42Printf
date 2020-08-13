/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:45:31 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/13 15:49:02 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

t_tab		g_tab[9] = {
	{'c', &ft_c}, {'s', &ft_s}, {'p', &ft_p},
	{'d', &ft_d}, {'i', &ft_d}, {'u', &ft_u},
	{'x', &ft_x}, {'X', &ft_xx}, {'%', &ft_prc}
};

void	ft_print_specifier(const char *format, va_list *args, t_prtf *struc)
{
	g_tab[ft_checktypes(format[struc->i])].tabFunc(args, struc);
}

int			ft_checktypes(char c)
{
	int		i;
	char	*types;

	i = 0;
	types = "cspdiuxX%";
	while (types[i])
	{
		if (types[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
