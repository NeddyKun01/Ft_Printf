/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:40:15 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/06 12:14:21 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Enche um bloco de memoria com o mesmo valor.
** EN: Fills a memory block with the same byte.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*bytes;
	size_t			i;

	bytes = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		bytes[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
