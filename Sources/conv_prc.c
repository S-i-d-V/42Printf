/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_prc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:00:14 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/03 15:25:43 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_prc(va_list *args, t_prtf *struc)
{
	(void)args;

	ft_putchar('%', struc);
}

void	spec_prc(va_list *args, t_prtf *struc)
{
	conv_prc(args, struc);
}