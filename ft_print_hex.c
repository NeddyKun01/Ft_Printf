/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char spec)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (spec == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, spec);
	count += ft_putchar(base[n % 16]);
	return (count);
}

static int	ft_putptr_base(unsigned long ptr)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_putptr_base(ptr / 16);
	count += ft_putchar(base[ptr % 16]);
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_putptr_base(ptr);
	return (count);
}
