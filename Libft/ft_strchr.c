/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 21:43:47 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/06 16:01:55 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Procura a primeira vez que c aparece na string.
** EN: Finds the first time c appears in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	target;

	if (!s)
		return (NULL);
	target = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == target)
			return ((char *)s);
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (NULL);
}
