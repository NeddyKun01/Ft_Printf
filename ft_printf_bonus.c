/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_dispatch_bonus(va_list args, t_fmt *fmt)
{
	if (fmt->spec == 'c')
		return (ft_render_char_bonus(va_arg(args, int), fmt));
	if (fmt->spec == 's')
		return (ft_render_str_bonus(va_arg(args, char *), fmt));
	if (fmt->spec == 'p')
		return (ft_render_ptr_bonus((unsigned long)va_arg(args, void *), fmt));
	if (fmt->spec == 'd' || fmt->spec == 'i')
		return (ft_render_snum_bonus(va_arg(args, int), fmt));
	if (fmt->spec == 'u')
		return (ft_render_unum_bonus(va_arg(args, unsigned int), fmt));
	if (fmt->spec == 'x' || fmt->spec == 'X')
		return (ft_render_hex_bonus(va_arg(args, unsigned int),
				fmt->spec, fmt));
	if (fmt->spec == '%')
		return (ft_render_percent_bonus(fmt));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_fmt	fmt;
	int		i;
	int		count;

	if (!format)
		return (0);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (!ft_parse_bonus(format, &i, &fmt))
				break ;
			count += ft_dispatch_bonus(args, &fmt);
			i++;
		}
		else
			count += ft_putchar_bonus(format[i++]);
	}
	va_end(args);
	return (count);
}
