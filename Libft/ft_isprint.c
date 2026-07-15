/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:36:38 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/01 22:37:27 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Ve se c pode ser impresso no ecra.
** EN: Checks if c is a printable ASCII character.
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
