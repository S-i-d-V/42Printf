/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:34 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/07 15:35:00 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_xx(va_list *args, t_prtf *struc)
{
	unsigned int n;

	n = va_arg(*args, unsigned int);
	ft_puthup(n, struc);
}
