/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 stdout_wrapper.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: vrybalko <vrybalko@student.unit.ua>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2018/05/12 00:24:19 by vrybalko		   #+#	  #+#			  */
/*	 Updated: 2018/05/12 00:27:34 by vrybalko		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include <unistd.h>
#define _GNU_SOURCE			   /* See feature_test_macros(7) */
#include <fcntl.h>			   /* Obtain O_* constant definitions */
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

static FILE		*g_file = NULL;
static int		g_save_fd = -1;

char	*read_temp_file(void)
{
		g_file = fopen("/tmp/gopa_file_temp", "rb");
		fseek(g_file, 0, SEEK_END);
		long int size = ftell(g_file);
		fseek(g_file, 0, SEEK_SET);
		char *buf = malloc(size + 1);
		fread(buf, size, 1, g_file);
		fclose(g_file);
		g_file = NULL;
		return buf;
}

void	set_stdout_to_temp_file(void)
{
		//save stdout fd
		g_save_fd = dup(STDOUT_FILENO);
		g_file = fopen("/tmp/gopa_file_temp", "w+");
		dup2(fileno(g_file), STDOUT_FILENO);
}

void	restore_stdout(void)
{
		fflush(stdout);
		fclose(g_file);
		g_file = NULL;
		dup2(g_save_fd, STDOUT_FILENO);
		close(g_save_fd);
}
