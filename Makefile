# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 12:02:10 by apitoise          #+#    #+#              #
#    Updated: 2021/06/29 17:25:17 by apitoise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = clang

INC = header/philo.h

CFLAGS = -Wall -Wextra -Werror

DIR_O = objs

SRCS = srcs/main.c srcs/utils.c srcs/init_data.c srcs/error.c \
		srcs/init_philo.c srcs/create_threads.c srcs/init_st.c \
		srcs/get_time.c srcs/routine.c srcs/display_message.c \
		srcs/ft_exit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
			mkdir -p objs
			$(CC) $(CFLAGS) -pthread -o $(NAME) $(OBJS) $(LIB)
			mv srcs/*.o objs 

clean: 
		rm -rf $(DIR_O)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re
