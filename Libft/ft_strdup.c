/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:57:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/05 19:37:03 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Faz uma copia nova da string toda na memoria.
** EN: Makes a new copy of the whole string in memory.
*/
char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s);
	copy = malloc(length + 1);
	if (!copy)
		return (NULL);
	while (i <= length)
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}
