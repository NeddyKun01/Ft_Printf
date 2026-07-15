/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:28:22 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/02 21:13:08 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Limpa memoria e poe zero em cada byte.
** EN: Clears memory by writing zero into each byte.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
