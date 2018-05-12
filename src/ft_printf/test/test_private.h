/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 22:11:30 by vrybalko          #+#    #+#             */
/*   Updated: 2018/05/12 08:01:46 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRIVATE_H
# define TEST_PRIVATE_H

# include <assert.h>

/*
 * Tests
 */

void		va_arg_test(void);

/*
 * Helper functions
 */

void		restore_stdout(void);
void		set_stdout_to_temp_file(void);
char		*read_temp_file(void);

#define GET_STDOUT_OUTPUT_TO(buf, expr) \
	do { 								\
		set_stdout_to_temp_file();		\
		expr;							\
		restore_stdout();				\
		(buf) = read_temp_file();		\
	} while(0);

#define MAKE_TEST(buf_printf, buf_ft, format, ...) 								\
	GET_STDOUT_OUTPUT_TO(buf_printf, printf(format, __VA_ARGS__));				\
	GET_STDOUT_OUTPUT_TO(buf_ft, ft_printf(format, __VA_ARGS__));				\
	if (strcmp(buf_printf, buf_ft) != 0)										\
	{																			\
		printf("ERROR! input: |%s, %s|\n", format, #__VA_ARGS__);				\
		printf("\t\tprintf: |%s|\n", buf_printf);								\
		printf("\t\t    ft: |%s|\n", buf_ft);									\
	}																			\
	free(buf_printf);															\
	free(buf_ft);																\

#endif
