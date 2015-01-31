/*
** set_pwd.h for set_pwd in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Mon Apr  8 16:50:49 2013 noel dovan
** Last update Fri May  3 10:20:31 2013 noel dovan
*/

#ifndef SET_PWD_H_
# define SET_PWD_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	"my.h"
# include	"string.h"

/* set_pwd.c */
t_all	*set_pwd_set(t_all *all, char ** check, char *pwd);
t_all	*set_pwd_read(t_all *all, char ** check, int *pipefd);
t_all	*set_pwd_fork(t_all *all, char ** check, int *pipefd, pid_t pid);
t_all	*set_pwd(t_all *all, char **check);

/* set_oldpwd.c */
t_all	*set_oldpwd_set(t_all *all, char **check, char *pwd);
t_all	*set_oldpwd(t_all *all, char **check);

#endif /* SET_PWD_H_ */
