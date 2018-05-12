/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_format_callbacks.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:02:01 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/12 14:53:39 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_FORMAT_CALLBACKS_H
# define FILL_FORMAT_CALLBACKS_H

# include "ft_printf_private.h"

void					fill_flags(char *s, int len, t_format *format);
void					fill_width(char *s, int len, t_format *format);
void					fill_precision(char *s, int len, t_format *format);
void					fill_conversion(char *s, int len, t_format *format);

#endif
