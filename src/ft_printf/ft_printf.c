/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:51:50 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/13 00:02:59 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "libft.h"

#                   include <stdio.h>

static char		*g_type_string[] =
{
	"%",
	"s",
	"S",
	"p",
	"d",
	"D",
	"i",
	"o",
	"O",
	"u",
	"U",
	"x",
	"X",
	"c",
	"C"
};
t_list			*parse_format_string(const char *format_string)
{
	t_list		*formats;
	t_format	format;
	char		*s;

	formats = NULL;
	s = (char*)format_string;
	while (s[0] && (s = ft_strchr(s, '%')))
	{
		printf("\n\n\ns: %s\n", s);
		s = s + 1;
		if (!s[0])
			continue ;
		ft_bzero((void*)&format, sizeof(t_format));
		fill_format_struct(s, &format);
		printf("type: %s\n", g_type_string[format.type]);
		printf("precision: %zu\n", format.precision);
		printf("width: %zu\n", format.width);
		printf("string: |%s|\n", format.string);
		printf("space: %d\n", format.flags.space);
		printf("hash: %d\n", format.flags.hash);
		printf("zero: %d\n", format.flags.zero);
		printf("minus: %d\n", format.flags.minus);
		printf("plus: %d\n", format.flags.plus);
		printf("hh: %d\n", format.flags.hh);
		printf("h: %d\n", format.flags.h);
		printf("ll: %d\n", format.flags.ll);
		printf("l: %d\n", format.flags.l);
		printf("j: %d\n", format.flags.j);
		printf("z: %d\n", format.flags.z);
		ft_lstadd(&formats, ft_lstnew(&format, sizeof(t_format)));
	}
	return (formats);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list		*formats;

	formats = parse_format_string(format);
	(void)formats;
	va_start(ap, format);
	ft_putnbr(va_arg(ap, int));
	va_end(ap);
	return 1;
}
