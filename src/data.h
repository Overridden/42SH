/*
** data.h for data in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 13:04:16 2013 noel dovan
** Last update Mon May 13 18:18:02 2013 noel dovan
*/

#ifndef DATA_H_
# define DATA_H_

# include "string.h"

# define	SIZE	61440
# define	PROMPT	"$>"
# define	SC	';'
# define	S_SC	";"
# define	PIPE	'|'
# define	S_PIPE	"|"
# define	EQUAL	'='
# define	AND	'&'
# define	S_AND	"&&"
# define	OR	'|'
# define	S_OR	"||"

typedef struct	s_env
{
  char		*name;
  char		*value;
  struct s_env	*next;
  struct s_env	*prev;
}		t_env;

typedef struct	s_all
{
  t_env		*env;
  int		ret;
  int		nul;
}		t_all;

t_all	*do_nul(t_all *all);

#endif /* DATA_H_ */
