/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:37:33 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/05 17:56:16 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Reserva memoria e mete tudo a zero.
** EN: Allocates memory and sets everything to zero.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*memory;

	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	total_size = nmemb * size;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, total_size);
	return (memory);
}
