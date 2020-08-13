/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoa_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:37:45 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/13 12:42:42 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

char		*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	sign;
	char			*str;

	len = lennb(n);
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	itoasign(&n, &sign);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (sign == 1)
		str[0] = '-';
	while (n != 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char		*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	unsigned int 	tmp;
	char			*str;

	len = 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
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

char	*ft_ltoa_hexa(unsigned long long n, char *base)
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