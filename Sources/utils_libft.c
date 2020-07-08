/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:08:18 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/07/09 01:08:57 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

void	ft_putchar(char c, t_prtf *struc)
{
	write(1, &c, 1);
	struc->ret++;
}

void	ft_putnbr(int nb, t_prtf *struc)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
		ft_putnbr(nb, struc);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, struc);
		ft_putchar((nb % 10) + 48, struc);
	}
	else
		ft_putchar(nb + 48, struc);
}

void	ft_putstr(char *str, t_prtf *struc)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], struc);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}