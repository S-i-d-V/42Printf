/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:15:05 by ugotheveny        #+#    #+#             */
/*   Updated: 2020/08/26 01:41:01 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int			ft_err_parse(char *format, int i)
{
	int		check;

	check = 0;
	while (format[i] && check != 1)
	{
		if (!ft_isdigit(format[i]) && ft_isflags(format[i]) < 0)
		{
			if (ft_istypes(format[i]) >= 0)
				check = 1;
			else
				return (-1);
		}
		else if (ft_istypes(format[i]) >= 0)
		{
			check = 1;
			break ;
		}
		else
			i++;
	}
	if (check == 1)
		return (1);
	else
		return (-1);
}

int			ft_isflags(char c)
{
	int		i;
	char	*flags;

	i = 0;
	flags = ".-0*";
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (-1);
}

int			ft_istypes(char c)
{
	int		i;
	char	*types;

	i = 0;
	types = "cspdiuxX%";
	while (types[i])
	{
		if (types[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
