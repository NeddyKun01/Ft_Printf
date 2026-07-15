/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:34:25 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/01 22:35:16 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Ve se c cabe na tabela ASCII.
** EN: Checks if c fits inside the ASCII table.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
