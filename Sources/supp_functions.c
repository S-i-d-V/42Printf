/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:44:54 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 01:38:28 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void		ft_strto(char *s, int n, t_prtf *struc)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (len < n)
		n = len;
	while (s[i] && i < n)
	{
		ft_putchar(s[i], struc);
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

char		*ft_revstr(char *s)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		len--;
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
	}
	return (s);
}
