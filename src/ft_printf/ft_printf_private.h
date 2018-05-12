/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:52:31 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/12 14:08:53 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define TRUE 1
# define FALSE 1

typedef enum		e_va_type
{
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
}					t_va_type;

typedef struct		s_flags
{
	bool			space;
	bool			hash;
	bool			zero;
	bool			minus;
	bool			plus;
	bool			hh;
	bool			h;
	bool			ll;
	bool			l;
	bool			j;
	bool			z;
}					t_flags;

typedef struct		s_format
{
	t_va_type		type;
	t_flags			flags;
	size_t			precision;
	size_t			width;
	char			*string;
}					t_format;

void			fill_format_struct(char *s, t_format *format);

#endif
