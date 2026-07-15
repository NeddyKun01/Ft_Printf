/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:17:32 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/05 17:36:26 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Pega no primeiro numero da string e transforma-o em int.
** EN: Reads the first number in the string and turns it into an int.
*/
int	ft_atoi(const char *nptr)
{
	int	index;
	int	sign;
	int	value;

	index = 0;
	sign = 1;
	value = 0;
	while (nptr[index] == ' ' || (nptr[index] >= '\t' && nptr[index] <= '\r'))
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			sign *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		value = value * 10 + (nptr[index] - '0');
		index++;
	}
	return (value * sign);
}
