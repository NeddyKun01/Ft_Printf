/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_base_setup_bonus(t_base *b)
{
	int	content;

	if (b->n == 0 && b->fmt->dot && b->fmt->precision == 0)
		b->digits = 0;
	else
		b->digits = ft_numlen_bonus(b->n, ft_strlen(b->base));
	b->zeros = 0;
	if (b->fmt->dot && b->fmt->precision > b->digits)
		b->zeros = b->fmt->precision - b->digits;
	content = ft_strlen(b->prefix) + b->zeros + b->digits;
	b->pad = 0;
	if (b->fmt->width > content)
		b->pad = b->fmt->width - content;
}

static int	ft_base_before_bonus(t_base *b)
{
	int	count;

	count = 0;
	if (b->fmt->minus)
		return (ft_putnstr_bonus(b->prefix, ft_strlen(b->prefix)));
	if (b->fmt->zero && !b->fmt->dot)
	{
		count += ft_putnstr_bonus(b->prefix, ft_strlen(b->prefix));
		count += ft_padding_bonus('0', b->pad);
	}
	else
	{
		count += ft_padding_bonus(' ', b->pad);
		count += ft_putnstr_bonus(b->prefix, ft_strlen(b->prefix));
	}
	return (count);
}

static int	ft_base_after_bonus(t_base *b)
{
	if (b->fmt->minus)
		return (ft_padding_bonus(' ', b->pad));
	return (0);
}

int	ft_render_base_bonus(unsigned long long n, char *base,
		char *prefix, t_fmt *fmt)
{
	t_base	b;
	int		count;

	b.n = n;
	b.base = base;
	b.prefix = prefix;
	b.fmt = fmt;
	ft_base_setup_bonus(&b);
	count = ft_base_before_bonus(&b);
	count += ft_padding_bonus('0', b.zeros);
	if (b.digits > 0)
		count += ft_putbase_bonus(b.n, b.base);
	count += ft_base_after_bonus(&b);
	return (count);
}
