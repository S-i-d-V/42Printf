/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:11:43 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/10 14:21:51 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int		ft_lenhexa(unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_revstr(char *str)
{
	int i;
	int len;
	char tmp;

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
	return(str);
}

char	*ft_itoa_hexa(unsigned int n, char *base)
{
	int len;
	int i;
	char *str;

	len = ft_lenhexa(n);
	i = 0;
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (n > 0)
	{
		str[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	str[i++] = '\0';
	return (ft_revstr(str));
}

int		ft_llenhexa(unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_ltoa_hexa(unsigned long long n, char *base)
{
	int len;
	int i;
	char *str;

	len = ft_llenhexa(n);
	i = 0;
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (n > 0)
	{
		str[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	str[i++] = '\0';
	return (ft_revstr(str));
}