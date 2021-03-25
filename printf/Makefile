# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 19:37:13 by hyenam            #+#    #+#              #
#    Updated: 2021/03/25 22:50:29 by hyenam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
LIBFT		= ../libft
LIBFT_LIB	= libft.a
CFLAGS = -Wall -Werror -Wextra
INC = -I.
CC = gcc
AR = ar rcs
RM = rm -rf

SRCS = 	ft_printf.c \
		put_char.c \
		put_nbr.c \
		put_str.c \

OBJS = $(SRCS:.c=.o)

all : ${NAME}

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

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
