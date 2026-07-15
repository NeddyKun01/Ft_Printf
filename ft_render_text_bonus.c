/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_text_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_render_char_bonus(int c, t_fmt *fmt)
{
	int	count;
	int	pad;

	count = 0;
	pad = 0;
	if (fmt->width > 1)
		pad = fmt->width - 1;
	if (!fmt->minus)
		count += ft_padding_bonus(' ', pad);
	count += ft_putchar_bonus((char)c);
	if (fmt->minus)
		count += ft_padding_bonus(' ', pad);
	return (count);
}

int	ft_render_str_bonus(char *str, t_fmt *fmt)
{
	int	count;
	int	len;
	int	pad;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (fmt->dot && fmt->precision < len)
		len = fmt->precision;
	pad = 0;
	if (fmt->width > len)
		pad = fmt->width - len;
	count = 0;
	if (!fmt->minus)
		count += ft_padding_bonus(' ', pad);
	count += ft_putnstr_bonus(str, len);
	if (fmt->minus)
		count += ft_padding_bonus(' ', pad);
	return (count);
}

int	ft_render_percent_bonus(t_fmt *fmt)
{
	int			count;
	int			pad;
	char		c;

	count = 0;
	pad = 0;
	c = ' ';
	if (fmt->zero && !fmt->minus)
		c = '0';
	if (fmt->width > 1)
		pad = fmt->width - 1;
	if (!fmt->minus)
		count += ft_padding_bonus(c, pad);
	count += ft_putchar_bonus('%');
	if (fmt->minus)
		count += ft_padding_bonus(' ', pad);
	return (count);
}
