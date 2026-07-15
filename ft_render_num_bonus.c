/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_num_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_render_snum_bonus(int n, t_fmt *fmt)
{
	long long			nb;
	unsigned long long	value;
	char				*prefix;

	nb = n;
	prefix = "";
	if (nb < 0)
	{
		prefix = "-";
		value = (unsigned long long)(-nb);
	}
	else
	{
		value = (unsigned long long)nb;
		if (fmt->plus)
			prefix = "+";
		else if (fmt->space)
			prefix = " ";
	}
	return (ft_render_base_bonus(value, "0123456789", prefix, fmt));
}

int	ft_render_unum_bonus(unsigned int n, t_fmt *fmt)
{
	return (ft_render_base_bonus(n, "0123456789", "", fmt));
}

int	ft_render_hex_bonus(unsigned int n, char spec, t_fmt *fmt)
{
	char	*base;
	char	*prefix;

	base = "0123456789abcdef";
	if (spec == 'X')
		base = "0123456789ABCDEF";
	prefix = "";
	if (fmt->hash && n != 0 && spec == 'x')
		prefix = "0x";
	else if (fmt->hash && n != 0 && spec == 'X')
		prefix = "0X";
	return (ft_render_base_bonus(n, base, prefix, fmt));
}

int	ft_render_ptr_bonus(unsigned long ptr, t_fmt *fmt)
{
	if (ptr == 0)
		return (ft_render_str_bonus("(nil)", fmt));
	return (ft_render_base_bonus(ptr, "0123456789abcdef", "0x", fmt));
}
