/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:54:37 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/05 20:06:06 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Cola s1 e s2 numa string nova.
** EN: Joins s1 and s2 into a new string.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	left_len;
	size_t	right_len;

	if (!s1 || !s2)
		return (NULL);
	left_len = ft_strlen(s1);
	right_len = ft_strlen(s2);
	result = malloc(left_len + right_len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, left_len);
	ft_memcpy(result + left_len, s2, right_len);
	result[left_len + right_len] = '\0';
	return (result);
}
