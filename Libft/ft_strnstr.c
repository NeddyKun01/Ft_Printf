/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 23:29:51 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/05 17:14:42 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Procura little dentro da parte visivel de big.
** EN: Searches little inside the visible part of big.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(little);
	i = 0;
	if (needle_len == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (i + needle_len <= len
			&& ft_strncmp(big + i, little, needle_len) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
