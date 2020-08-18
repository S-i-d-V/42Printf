/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:45:31 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/18 22:37:16 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int			ft_checktypes(char c)
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
