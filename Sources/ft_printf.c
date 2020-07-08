/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/08 13:32:22 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_prtf	struc;

	innit_struct(&struc);
	va_start(args, format);
	ft_parse(format, &args, &struc);
	va_end(args);
	return (struc.ret);
}
