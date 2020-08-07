/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:43:31 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/07 16:11:09 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Include/ft_printf.h"

void	itoasign(int *n, unsigned int *sign)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*sign = 1;
	}
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