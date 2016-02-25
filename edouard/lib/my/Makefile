##
## Makefile for Piscine_C_J10 in /home/puilla_e/Day10
## 
## Made by edouard puillandre
## Login   <puilla_e@epitech.net>
## 
## Started on  Fri Oct  9 18:22:18 2015 edouard puillandre
## Last update Sun Jan 24 18:25:43 2016 edouard puillandre
##

RM		= 	rm -f

AR		= 	ar rc

CP		=	cp

CFLAGS		= 	-Wall -Wextra -Werror

SRC		=	my_putchar.c \
			my_putstr.c \
			my_strlen.c \
			init_tab.c \
			my_fct_char.c \
			my_fct_nbr.c \
			my_fct_uns.c \
			my_printf.c \
			my_trad_nbr.c \
			my_trad_uns.c \
			my_print_nbracc.c \
			my_getnbr.c

NAME		= 	libmy.a

OBJ		= 	$(SRC:.c=.o)

LIB_DIR		= 	../

MY_DIR		= 	../../include

MY_HEADER	= 	./include/my.h


$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME) copylib copymy

copylib:
	$(CP) $(NAME) $(LIB_DIR)

copymy:
	$(CP) $(MY_HEADER) $(MY_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
