/*
** option_exit.h for option_exit in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 19:56:02 2013 noel dovan
** Last update Sun Apr 14 18:35:59 2013 noel dovan
*/

#ifndef OPTION_EXIT_H_
# define OPTION_EXIT_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	"string.h"
# include	"my.h"

# define	NBNULL		-1336
# define	NBNULL2		99213
# define	ERR_EXIT	"Error: exit failed.\n"
# define	ERR_EXIT_VALUE	"Error: exit bad expression.\n"

int	option_exit_value(char *buf);
t_all	*option_exit(char *buf, t_all *all, char **check);

#endif /* OPTION_EXIT_H_ */
