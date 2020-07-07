/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:04 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/07 16:16:15 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	flag_c(va_list *args, t_ptrf *struc)
{
	char c;

	c = (char)va_arg(*args, int);
	ft_putchar(c, struc);
}
