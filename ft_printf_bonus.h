/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_fmt
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		dot;
	char	spec;
}	t_fmt;

typedef struct s_base
{
	unsigned long long	n;
	char				*base;
	char				*prefix;
	int					digits;
	int					zeros;
	int					pad;
	t_fmt				*fmt;
}	t_base;

int		ft_printf(const char *format, ...);
int		ft_putchar_bonus(char c);
int		ft_putnstr_bonus(char *str, int len);
int		ft_padding_bonus(char c, int len);
int		ft_numlen_bonus(unsigned long long n, int base_len);
int		ft_putbase_bonus(unsigned long long n, char *base);
void	ft_init_bonus(t_fmt *fmt);
int		ft_parse_bonus(const char *format, int *i, t_fmt *fmt);
int		ft_render_char_bonus(int c, t_fmt *fmt);
int		ft_render_str_bonus(char *str, t_fmt *fmt);
int		ft_render_percent_bonus(t_fmt *fmt);
int		ft_render_snum_bonus(int n, t_fmt *fmt);
int		ft_render_unum_bonus(unsigned int n, t_fmt *fmt);
int		ft_render_hex_bonus(unsigned int n, char spec, t_fmt *fmt);
int		ft_render_ptr_bonus(unsigned long ptr, t_fmt *fmt);
int		ft_render_base_bonus(unsigned long long n, char *base,
			char *prefix, t_fmt *fmt);

#endif
