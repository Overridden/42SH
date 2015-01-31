/*
** option_env.c for option_env in /home/dovan_n//new_42sh/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Tue Apr 16 10:55:59 2013 noel dovan
** Last update Mon Apr 29 11:23:30 2013 noel dovan
*/

#include "data.h"
#include "option_env.h"

t_all	*option_env(char *buf, t_all *all, char **check)
{
  while (all->env->next)
    all->env = all->env->next;
  while (all->env->prev)
    {
      my_printf("%s=%s\n", all->env->name, all->env->value);
      all->env = all->env->prev;
    }
  my_printf("%s=%s\n", all->env->name, all->env->value);
  while (all->env->next)
    all->env = all->env->next;
  buf = buf;
  check = check;
  return (all);
}
