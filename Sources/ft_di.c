/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:28:16 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/19 00:06:13 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	ft_d(va_list *args, t_prtf *struc)
{
	int		n;
	char	*str;

	n = va_arg(*args, int);
	str = ft_itoa(n);
	struc->neg = (n < 0) ? 1 : 0;
	struc->len = ft_strlen(str);
	ft_display_int(str, struc);
	free(str);
	str = NULL;
}

void		ft_display_int(char *str, t_prtf *struc)
{
	if (struc->pad)
	{
		if (struc->dot)
		{
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->len, struc);
		}
		else
		{
			ft_strto(str, struc->len, struc);
			ft_fill(' ', struc->width - struc->len, struc);
		}
	}
	else if (struc->zero)
	{
		if (struc->dot)
		{
			ft_fill('0', struc->width - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
		else
		{
			if (struc->neg)
			{
				ft_putchar('-', struc);
				ft_fill('0', struc->width - struc->len, struc);
				str++;
				ft_strto(str, struc->len, struc);
			}
			else
			{
				ft_fill('0', struc->width - struc->len, struc);
				ft_strto(str, struc->len, struc);
			}
			
		}
	}
	else if (!struc->pad && struc->width)
	{
		if (struc->dot)
		{
			ft_fill('0', struc->width - struc->len, struc);
			ft_strto(str, struc->len, struc);
		}
		else
		{
			if (struc->neg)
			{
				ft_fill(' ', struc->width - struc->len, struc);
				ft_strto(str, struc->len, struc);
			}
			else
			{
				ft_fill(' ', struc->width - struc->len, struc);
				ft_strto(str, struc->len, struc);
			}
			
		}
	}
	else if (struc->dot)
		ft_strto(str, struc->prec, struc);
	else
		ft_strto(str, struc->len, struc);
}