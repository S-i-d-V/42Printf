/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:35:43 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/26 01:38:28 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	ft_putchar(char c, t_prtf *struc)
{
	write(1, &c, 1);
	struc->ret++;
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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

int		ft_atoi(char *s)
{
	int i;
	int nb;
	int nbsigne;

	i = 0;
	nb = 0;
	nbsigne = 0;
	while (s[i] == ' ' || (s[i] <= 13 && s[i] >= 9))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			nbsigne++;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	if (nbsigne == 1)
		nb = nb * -1;
	if (ft_strlen(s) > 1 || s[0] == 0)
		return (-1);
	return (nb);
}
