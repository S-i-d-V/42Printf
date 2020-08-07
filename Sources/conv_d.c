/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:11 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/07 13:40:41 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_d(va_list *args, t_prtf *struc)
{
	char *str;
	
	str = ft_itoa(va_arg(*args, int));
	spec_d(str, struc);
	free(str);
}

void	spec_d(char *str, t_prtf *struc)
{
	ft_putstr(str, struc);
}