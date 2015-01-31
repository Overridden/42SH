/*
** misc.h for misc in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Apr  4 21:55:43 2013 noel dovan
** Last update Sun May 26 06:07:52 2013 noel dovan
*/

#ifndef MISC_H_
# define MISC_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	"data.h"
# include	"my.h"

# define	SEPARATOR_ENV	'='
# define	S_SEPARATOR_ENV	"="
# define	TILD		'~'
# define	VARIABLE	'$'
# define	LEFT		0
# define	RIGHT		1
# define	ERR_VARIABLE	"Undefined variable.\n"
# define	ERR_MALLOC	"Error: Malloc failed.\n"
# define	ERR_SYNTAX	"Error: Syntax error.\n"
# define	ERR_NOUSER	"Unknow user: "

/* misc.c */
int	check_correct_red(char *buf);
int	count_car(char *line, char car);
void	clean_str(char *str);
void	epur_begin_end(char *str);
void	epur_str(char *str);

/* misc2.c */
int	already_in(t_env *env, char *buf);
int	isnt_printable(char *buf);
int	is_only_sc(char *buf);
int	is_str(char *buf, char *str);

/* misc3.c */
char	*get_side_value_right(char *line, char sep, char *buf);
char	*get_side_value_left(char *line, char sep, char *buf);
char	*get_side_value(char *line, char sep, int flag);
t_all	*seek_name_env(t_all *all, char *name);

/* misc4.c */
char	*get_the_variable(char *buf, int i);
char	*format_car_variable_cat(t_all *all, char *buf, int i, int k);
char	*format_car_variable(t_all *all, char *buf, int i);
char	*format_car_home(t_all *all, char *buf, int i);
char	*format_car(t_all *all, char *buf);

/* misc4_tilde.c */
int	format_car_tilde_line(char *buf, char *name);
char	*get_the_user(char *buf, int i);
int	format_car_tilde_seek(int fd, char *buff, char *buf, int i);
void	insert_tilde(char *buf, int i, char *buff, int line);
char	*format_car_tilde(char *buf, int i);

/* misc5.c */
void	epur_for_left_red(char *buf);
int	check_if_begin(char *buf, char *red, int i);
void	check_red_begin(char *buf, char *red);

#endif /* MISC_H_ */
