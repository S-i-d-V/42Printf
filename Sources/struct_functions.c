/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:46:15 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/13 14:21:43 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	innit_struct(t_prtf *struc)
{
	struc->i = 0;
	struc->ret = 0;
	struc->len = 0;
	struc->pad = 0;
	struc->zero = 0;
	struc->width = 0;
	struc->dot = 0;
	struc->fill = 0;
	struc->side = 0;
	struc->type = 0;
	struc-> neg = 0;
}

void	reset_flags(t_prtf *struc)
{
	struc->len = 0;
	struc->pad = 0;
	struc->zero = 0;
	struc->width = 0;
	struc->dot = 0;
	struc->fill = 0;
	struc->side = 0;
	struc->type = 0;
	struc->neg = 0;
}

void		ft_getfill(t_prtf *struc)
{
	if ((struc->type == 'd' || struc->type == 'i') && (struc->dot || struc->zero))
		struc->fill = '0';
	else if ((struc->type == 's' || struc->type == 'c') && struc->zero)
		struc->fill = '0';
	else
		struc->fill = ' ';
	if (struc->pad)
		struc->side = 0;
	else
		struc->side = 1;
	if (struc->pad || struc->dot)
		struc->zero = 0;
}

/*void		ft_getfill(t_prtf *struc)
{
	if ((struc->type == 'd' || struc->type == 'i') && (struc->dot || struc->zero))
	{
		struc->fill = '0';
		printf("DEBUG 1\n");
	}
	else if ((struc->type == 's' || struc->type == 'c') && struc->zero)
	{
		struc->fill = '0';
		printf("DEBUG 2\n");
	}
	else
	{
		struc->fill = ' ';
		printf("DEBUG 3\n");
	}
	if (struc->pad)
	{
		struc->side = 0;
		printf("DEBUG 4\n");
	}
	else
	{
		struc->side = 1;
		printf("DEBUG 5\n");
	}
	if (struc->pad || struc->dot)
	{
		struc->zero = 0;
		printf("DEBUG 6\n");
	}
	printf("SIDE = %d\n", struc->side);
	printf("DOT = %d\n", struc->dot);
	printf("PAD = %d\n", struc->pad);
	printf("ZERO = %d\n", struc->zero);
	printf("TYPE = %c\n", struc->type);
	printf("WIDTH = %d\n", struc->width);
}*/