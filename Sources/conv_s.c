/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:21 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/11 14:35:28 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_s(va_list *args, t_prtf *struc, t_flags *flags)
{
	char *str;
	(void)flags;

	str = va_arg(*args, char *);
	ft_putstr(str, struc);
}

void	spec_s(va_list *args, t_prtf *struc, t_flags *flags)
{
	conv_s(args, struc, flags);
}