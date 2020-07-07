/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:34 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/07 16:25:19 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	flag_xx(va_list *args, t_ptrf *struc)
{
	unsigned long long n;

	n = va_arg(*args, unsigned long long);
	ft_puthup(n, struc);
}
