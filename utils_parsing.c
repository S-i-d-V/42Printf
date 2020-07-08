/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:36:07 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/07 22:07:41 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

t_conv	g_conv[9] = {
	{'c', &conv_c}, {'s', &conv_s}, {'p', &conv_p},
	{'d', &conv_d}, {'i', &conv_i}, {'u', &conv_u},
	{'x', &conv_x}, {'X', &conv_xx}, {'%', &conv_prc}
};

void    ft_print_format(const char *format,va_list *args, t_prtf *struc)
{
    while (format[struc->i])
    {
        if (format[struc->i] == '%')
        {
            reset_struct(struc);
            struc->i++;
            g_conv[ft_checktype(format[struc->i])].tabFunc(args, struc);
        }
        else
            ft_putchar(format[struc->i], struc);
        struc->i++;
    }
}