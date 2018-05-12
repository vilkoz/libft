/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_format_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 09:48:56 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/13 01:14:23 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "fill_format_callbacks.h"
#include "ft_string.h"

#define FORMAT_REGEX "%[#+- 0]*[0-9](\.[0-9]+)?[hljz][sSpdDioOuUxXcC]"

typedef enum			e_format_state
{
	STATE_FLAGS,
	STATE_WIDHT,
	STATE_DOT,
	STATE_PRECISION,
	STATE_LENGTH_MODIFIER,
	STATE_CONVERSION,
	STATE_EXIT
}						t_format_state;

static char				*g_format_chars[] = {
	"#+- 0",
	"0123456789",
	".",
	"0123456789",
	"hljz",
	"%sSpdDioOuUxXcC",
	NULL
};

static t_format_state	g_next_state[] = {
	STATE_WIDHT,
	STATE_DOT,
	STATE_PRECISION,
	STATE_LENGTH_MODIFIER,
	STATE_CONVERSION,
	STATE_EXIT,
	STATE_EXIT
};

static void				(*g_fill_functions[])(char *, int len, t_format *) = {
	fill_flags,
	fill_width,
	NULL,
	fill_precision,
	fill_flags, //vrybalko TODO: fix hh triggering h issue
	fill_conversion,
	NULL
};

void					fill_format_struct(char *s, t_format *format)
{
	t_format_state		state;
	int					i;
	int					j;

	state = STATE_FLAGS;
	i = 0;
	while (s[i] != 0 && state != STATE_EXIT)
	{
		if (ft_strchr(g_format_chars[state], s[i]) != NULL)
		{
			j = i;
			while (s[j] && ft_strchr(g_format_chars[state], s[j])
					!= NULL)
			{
				j++;
				if (state == STATE_CONVERSION)
					break ;
			}
			if (j != i && g_fill_functions[state])
			{
				g_fill_functions[state](s + i, j - i, format);
			}
			i = j - 1;
			i++;
		}
		state = g_next_state[state];
	}
	format->string = ft_strsub(s, 0, i);
}
