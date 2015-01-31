/*
** main.h for main in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Apr  4 21:41:07 2013 noel dovan
** Last update Sun Apr 14 20:52:14 2013 noel dovan
*/

#ifndef MAIN_H_
# define MAIN_H_

# include	<unistd.h>
# include	<stdio.h>
# include	<signal.h>
# include	"my.h"
# include	"string.h"

# define	ERR_USE	"Usage: ./42sh\n"
# define	ERR_SIG	"Error: signal failed\n"
# define	ERR_ENV	"Error: environment creation failed\n"

void	ctrl_c(int sig);
t_env	*init_sh(int ac, char **ev);
int	exec_sh(t_all *all, char **check);
int	main(int ac, char **av, char **ev);

#endif /* MAIN_H_ */
