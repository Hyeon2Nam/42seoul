# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 19:37:13 by hyenam            #+#    #+#              #
#    Updated: 2021/03/24 03:33:59 by hyenam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
CFLAGS = -Wall -Werror -Wextra
CC = gcc
AR = ar rcs
RM = rm -rf
INC = -I.

SRCS = 	ft_printf.c \
		put_char.c \
		put_nbr.c \
		put_str.c \

OBJS = $(SRCS:.c=.o)

all : ${NAME}

$(NAME) : $(OBJS)
	make -C ../libft/
	$(AR) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(INC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS) 
	make clean -C ../libft/

fclean: clean
	$(RM) $(NAME) 
	make fclean -C ../libft/

re: fclean all

.PHONY: all clean fclean re
