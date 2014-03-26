##
## Makefile for Lem-in in /home/franck_r/rendu/lemin
## 
## Made by Romain Franck
## Login   <franck_r@epitech.net>
## 
## Started on  Fri Dec  6 18:59:15 2013 Romain Franck
## Last update Wed Mar 26 02:13:14 2014 Galleg_a
##

SRC =		main.c \
		nodes.c \
		str.c \
		getnextline.c \
	        getnbr.c

OBJ =		$(SRC:.c=.o)

NAME =		lem_in

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra -pedantic -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: $(NAME) clean fclean re
