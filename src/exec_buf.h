/*
** exec_buf.h for exec_buf in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 13:46:10 2013 noel dovan
** Last update Thu May 16 19:10:23 2013 noel dovan
*/

#ifndef EXEC_BUF_
# define EXEC_BUF_

# include	<stdlib.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	"my.h"

# define	ERR_EXEC	"Command not found.\n"
# define	ERR_PATH	"Error: PATH not found.\n"
# define	SEPARATOR_PATH	':'
# define	SEPARATOR_BUF	' '

int	exec_buf_execpath(char **av, t_env *env);
int	exec_buf_exec(char **path, char **av, char **ev, char *filename);
int	exec_buf_init(char **av, t_env *env, t_all *all);
int	exec_buf_fork(char **av, t_env *env, t_all *all);
int	exec_buf(char *buf, t_all *all);

#endif /* EXEC_BUF_ */
