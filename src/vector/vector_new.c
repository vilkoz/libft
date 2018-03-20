/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:29:38 by vrybalko          #+#    #+#             */
/*   Updated: 2018/03/20 15:18:00 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "memory.h"

t_vector		*vector_new(void *data, size_t data_size, size_t elem_size)
{
	t_vector	*v;

	if (elem_size == 0)
		return (NULL);
	v = ft_memalloc(sizeof(t_vector));
	if (data == NULL || data_size == 0)
		v->elems = NULL;
	else
		v->elems = ft_memalloc(data_size);
	v->size = data_size / elem_size;
	v->elem_size = elem_size;
	if (data != NULL)
		ft_memcpy(v->elems, data, data_size);
	return (v);
}
