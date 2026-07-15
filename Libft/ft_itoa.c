/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:28:27 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/05 21:54:11 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Conta quantos carateres a escrita do numero precisa.
** EN: Counts how many characters are needed to write the number.
*/
static size_t	num_len(long nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

/*
** PT: Transforma um numero inteiro numa string nova.
** EN: Turns an integer into a new string.
*/
char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*result;

	nb = n;
	len = num_len(nb);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		result[--len] = '0';
	while (nb > 0)
	{
		result[len - 1] = (nb % 10) + '0';
		nb /= 10;
		--len;
	}
	return (result);
}
