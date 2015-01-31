/*
** sh.h for sh in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Apr  4 21:43:05 2013 noel dovan
** Last update Thu May 16 18:53:46 2013 noel dovan
*/

#ifndef SH_H_
# define SH_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	"string.h"

t_all	*check_builtins(char *buf, t_all *all, char **check,
		       t_all *(*fonc[14])(char*, t_all*, char**));
t_all	*check_buf(char *buf, t_all *all, char **check);
t_all	*sh_read(t_all *all, char **check, char *buf);
t_all	*sh(t_all *all, char **check);

#endif /* SH_H_ */
