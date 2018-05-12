/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_format_callbacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:01:22 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/12 14:30:16 by vrybalko         ###   ########.fr       */
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
			break ;
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
