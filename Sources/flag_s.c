/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:21 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/07 16:25:19 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	flag_s(va_list *args, t_ptrf *struc)
{
	char *str;

	str = va_arg(*args, char *);
	ft_putstr(str, struc);
}
