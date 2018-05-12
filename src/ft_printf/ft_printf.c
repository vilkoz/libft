/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:51:50 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/12 09:49:25 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "libft.h"

t_list			*parse_format_string(const char *format_string)
{
	t_list		*formats;
	t_format	format;
	char		*s;

	formats = NULL;
	while ((s = ft_strchr(format_string, '%')))
	{
		fill_format_struct(s, &format);
		ft_lstadd(&formats, ft_lstnew(&format, sizeof(t_format)));
	}
	return (formats);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list		*formats;

	formats = parse_format_string(format);
	va_start(ap, format);
	ft_putnbr(va_arg(ap, int));
	va_end(ap);
	return 1;
}
