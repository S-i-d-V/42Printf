/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:16 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/07 15:02:31 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_i(va_list *args, t_prtf *struc)
{
	int n;
	char *str;
	
	n = va_arg(*args, int);
	str = ft_itoa(n);
	struc->neg = (n < 0) ? 1 : 0;
	struc->len = ft_strlen(str);
	spec_d(str, struc);
	free(str);
}

void	spec_i(char *str, t_prtf *struc)
{
	if (struc->dot && struc->side == 1)
		dot_d(str, struc);
	else if (struc->pad && struc->side == 0)
		pad_d(str, struc);
	else if (!struc->pad && !struc-> dot && !struc->zero)
		width_d(str, struc);
	else if (struc->zero)
		zero_d(str, struc);
}
