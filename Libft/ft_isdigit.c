/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:30:52 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/01 22:32:46 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Ve se c e um numero de 0 a 9.
** EN: Checks if c is a digit from 0 to 9.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
