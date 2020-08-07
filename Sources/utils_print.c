/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:58:28 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/07 15:02:31 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

t_tab		g_tab[9] = {
	{'c', &spec_c}, {'s', &conv_s}, {'p', &spec_p},
	{'d', &conv_d}, {'i', &conv_i}, {'u', &spec_u},
	{'x', &spec_x}, {'X', &spec_xx}, {'%', &spec_prc}
};

void	ft_print_specifier(const char *format, va_list *args, t_prtf *struc)
{
	g_tab[ft_checktype(format[struc->i])].tabFunc(args, struc);
}