/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_bonus(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnstr_bonus(char *str, int len)
{
	int	str_len;

	if (!str || len <= 0)
		return (0);
	str_len = ft_strlen(str);
	if (len > str_len)
		len = str_len;
	return (write(1, str, len));
}

int	ft_padding_bonus(char c, int len)
{
	char	buffer[64];
	int		i;
	int		chunk;
	int		count;

	i = 0;
	while (i < 64)
		buffer[i++] = c;
	count = 0;
	while (len > 0)
	{
		chunk = 64;
		if (len < chunk)
			chunk = len;
		count += write(1, buffer, chunk);
		len -= chunk;
	}
	return (count);
}
