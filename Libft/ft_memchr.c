/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:45:47 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/02 23:00:27 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Procura um byte dentro dos primeiros n bytes.
** EN: Searches for a byte in the first n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*current;
	size_t			i;

	current = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*current == (unsigned char)c)
			return (current);
		current++;
		i++;
	}
	return (NULL);
}
