/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 22:06:42 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/12 08:01:40 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"
#include <stdio.h> 
#include "test_private.h"

void		va_arg_test(void)
{
	char		*buf_printf;
	char		*buf_ft;

	MAKE_TEST(buf_printf, buf_ft, "n: %d", 3);
}
