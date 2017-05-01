/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 23:46:52 by vrybalko          #+#    #+#             */
/*   Updated: 2017/05/01 15:41:12 by tor              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_nums(const char *s)
{
	int		i;

	i = -1;
	while (ft_isdigit(s[++i]))
		;
	i++;
	while (s[--i] == '0')
		;
	return (i);
}

static double	ft_pow(double x, int c)
{
	double	res;

	res = 1;
	while (c)
	{
		res *= x;
		c--;
	}
	return (res);
}

double			ft_atod(const char *s)
{
	int		a;
	int		b;
	int		is_neg;
	char	*minus;
	char	*dot;

	if ((a = ft_atoi(s)) == 0 &&
			(minus = ft_strchr(s, '-')))
		is_neg = 1;
	dot = ft_strchr(s, '.');
	if (minus && dot && minus > dot)
		is_neg = 0;
	if (dot)
	{
		b = ft_atoi(ft_strchr(s, '.') + 1);
		return (((double)a + (a < 0 ? -1 : 1) * ((double)b /
			(double)ft_pow(10, count_nums(ft_strchr(s, '.') + 1)))) *
			(is_neg && a == 0 ? -1. : 1.));
	}
	return ((double)a);
}
