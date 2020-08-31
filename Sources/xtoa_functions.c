/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoa_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:37:45 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/31 16:47:20 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

char				*ft_itoapos(int n)
{
	unsigned int	len;
	char			*s;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		n = n * -1;
	len = lennb(n);
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[len--] = '\0';
	while (n != 0)
	{
		s[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (s);
}

char				*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	unsigned int	tmp;
	char			*s;

	len = 0;
	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[len--] = '\0';
	while (n != 0)
	{
		s[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (s);
}

char				*ft_itoa_hexa(unsigned long long n, char *base)
{
	int				len;
	int				i;
	char			*s;

	len = ft_lenhexa(n);
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if ((s = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (n > 0)
	{
		s[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	s[i++] = '\0';
	return (ft_revstr(s));
}
