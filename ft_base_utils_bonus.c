/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_numlen_bonus(unsigned long long n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned long long)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

int	ft_putbase_bonus(unsigned long long n, char *base)
{
	int					count;
	unsigned long long	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		count += ft_putbase_bonus(n / base_len, base);
	count += ft_putchar_bonus(base[n % base_len]);
	return (count);
}
