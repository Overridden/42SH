/*
** option_env.h for option_env in /home/dovan_n//new_42sh/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Tue Apr 16 10:56:42 2013 noel dovan
** Last update Tue Apr 30 16:02:02 2013 noel dovan
*/

#ifndef OPTION_ENV_H_
# define OPTION_ENV_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	"my.h"

# define	ERR_SETENV	"setenv: Too many arguments\n"
# define	ERR_ADD		"Error: setenv failed\n"

# define	ERR_UNSET_ARG	"unsetenv: Too few arguments.\n"
# define	ERR_UNSET_NO	"Variable not found.\n"

/* option_env.c */
t_all	*option_env(char *buf, t_all *all, char **check);

/* option_setenv.c */
t_env	*option_setenv_name_value_set(t_env *env, char *name, char *value);
t_all	*option_setenv_name_value2(char *buf, t_all *all, char *name, int i);
t_all	*option_setenv_name_value(char *buf, t_all *all);
t_all	*option_setenv_name(char *buf, t_all *all);
t_all	*option_setenv(char *buf, t_all *all, char **check);

/* option_setenv2.c */
t_env	*option_setenv_fill(t_env **env, char *name, char *value);
int	option_setenv_check(char *buf, t_all *all);

/* option_unsetenv.c */
t_env	*option_unsetenv_rm(t_env *env, char *name);
t_env	*option_unsetenv_parse(char *buf, t_env *env, int ac);
int	option_unsetenv_check(char *buf);
t_all	*option_unsetenv(char *buf, t_all *all, char **check);

#endif /* OPTION_ENV_H_ */
