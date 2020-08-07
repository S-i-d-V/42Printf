/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:31:31 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/07 15:51:42 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int		ft_strto(char *str, int n, t_prtf *struc)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	if (len < n)
		n = len;
	while (str[i] && i < n)
	{
		ft_putchar(str[i], struc);
		i++;
	}
	return (i);
}

void	ft_fill(char c, int n, t_prtf *struc)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c, struc);
		i++;
	}
}

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

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	lennb(int n)
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