/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:38:43 by vrybalko          #+#    #+#             */
/*   Updated: 2018/03/20 15:54:42 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "memory.h"

void		vector_add(t_vector *v, void *elem)
{
	if (v == NULL || elem == NULL)
		return ;
	v->elems = ft_realloc(v->elems, v->elem_size * v->size,
			v->elem_size * (v->size + 1));
	ft_memcpy(v->elems + v->size * v->elem_size, elem, v->elem_size);
	v->size += 1;
}
