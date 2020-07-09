/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:04 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/09 15:46:12 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_c(va_list *args, t_prtf *struc, t_flags *flags)
{
	char c;
	(void)flags;

	c = (char)va_arg(*args, int);
	ft_putchar(c, struc);
}
