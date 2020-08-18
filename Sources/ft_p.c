/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:31:25 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/18 19:41:04 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void					ft_p(va_list *args, t_prtf *struc)
{
	unsigned long long	n;
	char				*str;

	n = va_arg(*args, unsigned long long);
	str = ft_ltoa_hexa(n, "0123456789abcdef");
	struc->len = ft_strlen(str);
	ft_strto(str, struc->len, struc);
	free(str);
}