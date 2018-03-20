/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:29:58 by vrybalko          #+#    #+#             */
/*   Updated: 2018/03/20 16:02:07 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

typedef struct		s_vector
{
	void			*elems;
	size_t			size;
	size_t			elem_size;
}					t_vector;

# define VECTOR_GET_TO(var, v, i) var = (typeof(var))vector_get(v, i)
# define VECTOR_SET(var, v, i) vector_set(v, i, (void*)var)
# define VECTOR_ADD(v, var) vector_add(v, (void*)var)

t_vector			*vector_new(void *data, size_t data_size, size_t elem_size);
void				vector_add(t_vector *v, void *elem);
void				*vector_get(t_vector *v, size_t i);
void				vector_set(t_vector *v, size_t i, void *data);

#endif
