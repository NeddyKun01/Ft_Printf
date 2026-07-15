/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 00:08:06 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/06 12:14:44 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Junta src ao fim de dst sem passar o limite.
** EN: Appends src to dst without crossing the buffer limit.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (src_len + size);
	i = 0;
	while (dst_len + i + 1 < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
