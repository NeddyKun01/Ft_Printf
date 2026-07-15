/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:06:15 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/02 22:41:52 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Copia da frente para tras quando e seguro.
** EN: Copies from left to right when that direction is safe.
*/
static void	ft_memmove_forward(unsigned char *d, const unsigned char *s,
		size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

/*
** PT: Copia do fim para o inicio quando ha sobreposicao.
** EN: Copies from right to left when the areas overlap.
*/
static void	ft_memmove_backward(unsigned char *d, const unsigned char *s,
		size_t n)
{
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
}

/*
** PT: Move n bytes sem estragar memoria que se sobrepoe.
** EN: Moves n bytes without breaking overlapping memory.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (dest == src || n == 0)
		return (dest);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (d < s)
		ft_memmove_forward(d, s, n);
	else
		ft_memmove_backward(d, s, n);
	return (dest);
}
