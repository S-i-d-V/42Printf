/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:25 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/09 15:46:52 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_u(va_list *args, t_prtf *struc, t_flags *flags)
{
	unsigned int n;
	(void)flags;

	n = va_arg(*args, unsigned int);
	ft_putui(n, struc);
}
