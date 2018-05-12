# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/11 22:00:45 by vrybalko          #+#    #+#              #
#    Updated: 2018/05/12 00:35:34 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf_test

CC=gcc

FLAGS=-Wall -Wextra -Werror -g

all: $(NAME)

SRCS= main.c					\
	  stdout_wrapper.c			\
	  va_arg_test.c

BIN_DIR=bin/

BINS=$(addprefix $(BIN_DIR), $(SRCS:.c=.o))

$(BIN_DIR)%.o: %.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(BINS)
	$(CC) $(FLAGS) -o $(NAME) $(BINS) ../../../libftprintf.a


