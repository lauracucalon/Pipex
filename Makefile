# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lacucalo <lacucalo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 16:51:49 by lacucalo          #+#    #+#              #
#    Updated: 2023/12/05 15:43:26 by lacucalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SOURCES = pipex.c pipex_utils.c

OBJ = $(SOURCES:.c=.o)

RM = rm -fr

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
	
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		
re: fclean all

.PHONY: all clean fclean re