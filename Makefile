##
## Makefile for PSU_2015_tetris in /home/puilla_e/Semestre2/
## 
## Made by edouard puillandre
## Login   <puilla_e@epitech.net>
## 
## Started on  Thu Feb 25 18:45:44 2016 edouard puillandre
## Last update Sat Mar 12 14:56:14 2016 edouard puillandre
##

DEBUG	=	yes

CC	=	gcc

CFLAGS	=	-Iinclude	\
		-Wall		\
		-Wextra		\
		-Werror		\
		-std=c99

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g		\
		-D DEBUG	
endif

LDFLAGS	=	-lmy		\
		-L./lib/	\
		-lncurses

SRC	=	src/main.c		\
		src/fct_str.c		\
		src/fct_option.c	\
		src/fct_opt2.c		\
		src/fct_opt3.c		\
		src/fct_opt4.c		\
		src/fct_opt5.c		\
		src/fct_check.c		\
		src/fct_init_tet.c	\
		src/fct_exit.c		\
		src/fct_debug.c		\
		src/fct_score.c		\
		src/get_next_line.c	\
		src/fct_cmd.c		\
		src/malloc.c		\
		src/fct_parsing.c	\
		src/fct_list.c

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
