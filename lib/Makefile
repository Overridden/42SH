##
## Makefile for Makefile in /home/dovan_n//svn/42sh-2017-nguye_1/lib
## 
## Made by noel dovan
## Login   <dovan_n@epitech.net>
## 
## Started on  Sun Apr 28 11:30:00 2013 noel dovan
## Last update Fri May 24 13:25:02 2013 noel dovan
##

NAME	= libmy.a

SRCS	= my_printf.c \
	my_printf_flag.c \
	my_printf_flag2.c \
	my_printf_flag3.c \
	my_printf_flag4.c \
	my_printf_flag5.c \
	my_printf_fonc.c \
	my_printf_fonc2.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putnbr.c \
	my_putnbr_base.c \
	my_putstr.c \
	my_strlen.c \
	my_getnbr.c \
	my_strcpy.c \
	my_strcmp.c \
	my_strcat.c \
	my_strdup.c \
	my_get_unsign.c \
	my_put_unsign.c \
	convert_base.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS = -W -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
