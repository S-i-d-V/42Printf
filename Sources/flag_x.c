/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:23:30 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/07 13:43:24 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	flag_x(va_list *args)
{
	unsigned long long n;

	n = va_arg(*args, unsigned long long);
	ft_puthlow(n);
}
