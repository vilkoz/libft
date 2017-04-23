/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 23:46:52 by vrybalko          #+#    #+#             */
/*   Updated: 2017/04/24 00:19:22 by vrybalko         ###   ########.fr       */
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

	a = ft_atoi(s);
	if (ft_strchr(s, '.') != NULL)
	{
		b = ft_atoi(ft_strchr(s, '.') + 1);
		return ((double)a + ((double)b /
			(double)ft_pow(10, count_nums(ft_strchr(s, '.') + 1))));
	}
	return ((double)a);
}
