/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:44:54 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/25 14:46:48 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_strto(char *str, int n, t_prtf *struc)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (len < n)
		n = len;
	while (str[i] && i < n)
	{
		ft_putchar(str[i], struc);
		i++;
	}
}

void		ft_fill(char c, int n, t_prtf *struc)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c, struc);
		i++;
	}
}

char		*ft_revstr(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		len--;
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
	}
	return (str);
}
