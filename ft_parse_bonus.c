/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_bonus(t_fmt *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->hash = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->dot = 0;
	fmt->spec = 0;
}

static int	ft_isflag_bonus(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == '+'
		|| c == ' ');
}

static void	ft_flags_bonus(const char *format, int *i, t_fmt *fmt)
{
	while (ft_isflag_bonus(format[*i]))
	{
		if (format[*i] == '-')
			fmt->minus = 1;
		else if (format[*i] == '0')
			fmt->zero = 1;
		else if (format[*i] == '#')
			fmt->hash = 1;
		else if (format[*i] == '+')
			fmt->plus = 1;
		else if (format[*i] == ' ')
			fmt->space = 1;
		(*i)++;
	}
}

static int	ft_number_bonus(const char *format, int *i)
{
	int	n;

	n = 0;
	while (ft_isdigit(format[*i]))
	{
		n = n * 10 + format[*i] - '0';
		(*i)++;
	}
	return (n);
}

int	ft_parse_bonus(const char *format, int *i, t_fmt *fmt)
{
	ft_init_bonus(fmt);
	(*i)++;
	ft_flags_bonus(format, i, fmt);
	fmt->width = ft_number_bonus(format, i);
	if (format[*i] == '.')
	{
		fmt->dot = 1;
		(*i)++;
		fmt->precision = ft_number_bonus(format, i);
	}
	fmt->spec = format[*i];
	if (!fmt->spec)
		return (0);
	return (1);
}
