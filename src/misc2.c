/*
** misc2.c for misc2 in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 01:01:16 2013 noel dovan
** Last update Fri May 31 04:56:45 2013 alexandre1 nguyen
*/

#include "data.h"
#include "misc.h"

t_all	*do_nul(t_all *all)
{
  all->nul = 1;
  return (all);
}

int	already_in(t_env *env, char *buf)
{
  while (env->next)
    env = env->next;
  while (env->prev)
    {
      if (my_strcmp(env->name, buf) == 0)
  	{
	  while (env->next)
	    env = env->next;
	  return (1);
	}
      env = env->prev;
    }
  if (my_strcmp(env->name, buf) == 0)
    {
      while (env->next)
	env = env->next;
      return (1);
    }
  while (env->next)
    env = env->next;
  return (0);
}

int	isnt_printable(char *buf)
{
  int	i;

  i = -1;
  while (buf[++i] != '\0')
    {
      if ((buf[i] < 32 && buf[i] != '\n' && buf[i] != '\t') || buf[i] > 126)
	return (1);
    }
  return (0);
}

int	is_only_sc(char *buf)
{
  int	i;

  i = 0;
  while (buf[i] != '\0')
    {
      if (buf[i] != ';')
	return (0);
      ++i;
    }
  return (1);
}

int	is_str(char *buf, char *str)
{
  int	i;
  int	j;

  i = -1;
  while (buf[++i] != '\0')
    {
      j = 0;
      if (buf[i] == str[j])
	{
	  while (str[j] != '\0' && buf[i] == str[j])
	    {
	      ++j;
	      ++i;
	      if (buf[i] == '\0' && str[j] != '\0')
		return (0);
	    }
	  if (str[j] == '\0')
	    {
	      if (buf[i] == str[j - 1])
		return (0);
	      return (1);
	    }
	}
    }
  return (0);
}
