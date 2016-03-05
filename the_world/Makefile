##
## Makefile for PSU_2015_tetris in /home/puilla_e/Semestre2/
## 
## Made by edouard puillandre
## Login   <puilla_e@epitech.net>
## 
## Started on  Thu Feb 25 18:45:44 2016 edouard puillandre
## Last update Sat Mar  5 14:32:24 2016 Voyevoda
##

DEBUG	=	yes

CC	=	gcc

CFLAGS	=	-I../include	\
		-Wall		\
		-Wextra		\
		-Werror		\
		-std=c99

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g		\
		-D DEBUG	
endif

LDFLAGS	=	-lmy	\
		-L../lib/

SRC	=	main.c		\
		get_next_line.c	\
		malloc.c	\
		my_getnbr.c	

RM	=	rm -f

NAME	=	tetris

OBJ	=	$(SRC:.c=.o)

$(NAME): $(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 2; tput bold
	@echo
	@echo Debug mode
	@echo
	@tput sgr0
endif
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
