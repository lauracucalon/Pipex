# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lacucalo <lacucalo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 16:51:49 by lacucalo          #+#    #+#              #
#    Updated: 2023/12/04 17:03:07 by lacucalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

OBJ = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs

SOURCES = pipex.c pipex_utils.c

RM = rm -fr

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) $?
	
clean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re