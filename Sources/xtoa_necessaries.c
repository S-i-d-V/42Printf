/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoa_necessaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:40:09 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/25 14:44:11 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int					lennb(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		if (len < 0)
			n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int					ft_lenhexa(unsigned long long n)
{
	int				i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
