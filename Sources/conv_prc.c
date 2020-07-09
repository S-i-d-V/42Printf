/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_prc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:00:14 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 15:46:52 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	conv_prc(va_list *args, t_prtf *struc, t_flags *flags)
{
	(void)args;
	(void)flags;

	ft_putchar('%', struc);
}
