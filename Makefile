##
## Makefile for Makefile in /home/dovan_n//svn/biji-repo1
## 
## Made by noel dovan
## Login   <dovan_n@epitech.net>
## 
## Started on  Thu Apr  4 16:48:33 2013 noel dovan
## Last update Fri May 31 02:09:14 2013 alexandre1 nguyen
##

NAME	= 42sh

SRCS	= src/main.c \
	src/create_env.c \
	src/create_check.c \
	src/sh.c \
	src/misc.c \
	src/misc2.c \
	src/misc3.c \
	src/misc4.c \
	src/misc4_tilde.c \
	src/misc5.c \
	src/exec_buf.c \
	src/init_tab.c \
	src/create_env_tab.c \
	src/option_signal.c \
	src/option_sc.c \
	src/option_and.c \
	src/option_or.c \
	src/option_pipe.c \
	src/option_red_leftl.c \
	src/option_red_rightr.c \
	src/option_red_left.c \
	src/option_red_right.c \
	src/option_exit.c \
	src/option_echo.c \
	src/option_cd.c \
	src/option_cd2.c \
	src/set_pwd.c \
	src/set_oldpwd.c \
	src/option_unsetenv.c \
	src/option_setenv.c \
	src/option_setenv2.c \
	src/option_env.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

LIB	= -lmy -Llib

CFLAGS	= -W -Wall -Werror -Wextra -Ilib -g3

$(NAME):	$(OBJS)
	cd lib; make
	cc -o $(NAME) $(OBJS) $(LIB)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	cd lib; make fclean
	$(RM) $(NAME)

re:	fclean all
