/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_format_callbacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:01:22 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/12 15:01:28 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_string.h"

# define FLAGS_NUM 11

static char				*g_flags[] = {
	" ",
	"#",
	"0",
	"-",
	"+",
	"hh",
	"h",
	"ll",
	"l",
	"j",
	"z",
};

static size_t			g_flag_offsets[] = {
	offsetof(t_flags, space),
	offsetof(t_flags, hash),
	offsetof(t_flags, zero),
	offsetof(t_flags, minus),
	offsetof(t_flags, plus),
	offsetof(t_flags, hh),
	offsetof(t_flags, h),
	offsetof(t_flags, l),
	offsetof(t_flags, ll),
	offsetof(t_flags, j),
	offsetof(t_flags, z)
};

static void				set_flag(int flag_num, t_flags *flags)
{
	bool		*flag_addr;

	flag_addr = (bool*)flags + g_flag_offsets[flag_num];
	*flag_addr = TRUE;
}

void					fill_flags(char *s, int len, t_format *format)
{
	int		i;
	int		j;

	i = -1;
	while (s[++i] && i < len)
	{
		j = -1;
		while (++j < FLAGS_NUM)
		{
			if (ft_strncmp(g_flags[j], s + i, ft_strlen(g_flags[j])) == 0)
			{
				set_flag(j, &(format->flags));
				break ;
			}
		}
		// vrybalko TODO: ERROR NO SUCH FLAG
		if (j == FLAGS_NUM)
		{
			break ;
		}
	}
}

void					fill_width(char *s, int len, t_format *format)
{
	char		*str;

	str = ft_strsub(s, 0, len);
	format->width = ft_atoi(str);
	ft_strdel(&str);
}

void					fill_precision(char *s, int len, t_format *format)
{
	char		*str;

	str = ft_strsub(s, 0, len);
	format->precision = ft_atoi(str);
	ft_strdel(&str);
}

static char				*g_conversions = "%sSpdDioOuUxXcC";

static t_va_type		g_conversion_types[] = {
	ARG_percent_symbol,
	ARG_s,
	ARG_S,
	ARG_p,
	ARG_d,
	ARG_D,
	ARG_i,
	ARG_o,
	ARG_O,
	ARG_u,
	ARG_U,
	ARG_x,
	ARG_X,
	ARG_c,
	ARG_C
};

void					fill_conversion(char *s, int len, t_format *format)
{
	int			i;

	(void)len;
	i = 0;
	while (g_conversions[i] && g_conversions[i] != s[0])
	{
		i++;
	}
	if (i == (sizeof(g_conversion_types) / sizeof(g_conversion_types[0])))
	{
		// vrybalko TODO: error management
		return ;
	}
	format->type = g_conversion_types[i];
}
