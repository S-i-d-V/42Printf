/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:58:28 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/07 15:35:00 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

t_tab		g_tab[9] = {
	{'c', &conv_c}, {'s', &conv_s}, {'p', &conv_p},
	{'d', &conv_d}, {'i', &conv_d}, {'u', &conv_u},
	{'x', &conv_x}, {'X', &conv_xx}, {'%', &conv_prc}
};

void	ft_print_specifier(const char *format, va_list *args, t_prtf *struc)
{
	g_tab[ft_checktype(format[struc->i])].tabFunc(args, struc);
}