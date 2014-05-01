##
## Makefile for Lem-in in /home/franck_r/rendu/lemin
## 
## Made by Romain Franck
## Login   <franck_r@epitech.net>
## 
## Started on  Fri Dec  6 18:59:15 2013 Romain Franck
## Last update Thu May  1 03:05:45 2014 root
##

SRC =		main.c \
		nodes.c \
		str.c \
		getnextline.c \
	        getnbr.c \
		ants.c \
		create_tree.c \
	  	epur_tree.c \
		link_everything.c

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
