/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:51:48 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/07 11:52:37 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	flag_p(va_list *args)
{
	unsigned long long n;

	n = va_arg(*args, unsigned long long);
	write(1, "0x", 2);
	ft_puthlow(n);
}
