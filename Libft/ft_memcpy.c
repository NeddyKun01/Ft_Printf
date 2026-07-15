/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 21:39:01 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/02 22:05:39 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Copia bytes de src para dest.
** EN: Copies bytes from src to dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	size_t				i;

	source = (const unsigned char *)src;
	destination = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
