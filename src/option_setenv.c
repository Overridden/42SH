/*
** option_setenv.c for option_setenv in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 20:13:00 2013 noel dovan
** Last update Mon Apr 29 13:42:42 2013 noel dovan
*/

#include "data.h"
#include "option_env.h"
#include "misc.h"

t_env	*option_setenv_name_value_set(t_env *env, char *name, char *value)
{
  while (env)
    {
      if (my_strcmp(env->name, name) == 0)
	{
	  env->value = my_strcpy(env->value, value);
	  while (env->prev)
	    env = env->prev;
	  return (env);
	}
      env = env->next;
    }
  return (env);
}

t_all	*option_setenv_name_value2(char *buf, t_all *all, char *name, int i)
{
  char	*value;
  int	j;

  if (!(value = malloc(sizeof(*value) * (my_strlen(buf) + 1))))
    return (NULL);
  j = 0;
  while (buf[++i] != '\0')
    value[j++] = buf[i];
  value[j] = '\0';
  if (already_in(all->env, name) == 1)
    {
      all->env = option_setenv_name_value_set(all->env, name, value);
      free(value);
      return (all);
    }
  if (!(all->env = option_setenv_fill(&all->env, name, value)))
    {
      free(value);
      return (do_nul(all));
    }
  free(value);
  return (all);
}

t_all	*option_setenv_name_value(char *buf, t_all *all)
{
  char	*name;
  int	i;
  int	j;

  if (!(name = malloc(sizeof(*name) * my_strlen(buf))))
    return (do_nul(all));
  i = -1;
  while (buf[++i] != ' ')
    ;
  j = 0;
  while (buf[++i] != ' ')
    name[j++] = buf[i];
  name[j] = '\0';
  if ((all = option_setenv_name_value2(buf, all, name, i))->nul == 1)
    {
      free(name);
      return (do_nul(all));
    }
  free(name);
  return (all);
}

t_all	*option_setenv_name(char *buf, t_all *all)
{
  char	*name;
  int	i;
  int	j;

  if (!(name = malloc(sizeof(*name) * my_strlen(buf))))
    return (do_nul(all));
  i = -1;
  while (buf[++i] != ' ')
    ;
  j = 0;
  while (buf[++i] != '\0')
    name[j++] = buf[i];
  name[j] = '\0';
  if (already_in(all->env, name) == 1)
    {
      free(name);
      return (all);
    }
  if (!(all->env = option_setenv_fill(&all->env, name, NULL)))
    {
      free(name);
      return (do_nul(all));
    }
  free(name);
  return (all);
}

t_all	*option_setenv(char *buf, t_all *all, char **check)
{
  int	ac;

  check = check;
  if ((ac = option_setenv_check(buf, all)) == -1)
    return (all);
  else if (ac == -2)
    return (do_nul(all));
  while (all->env->prev)
    all->env = all->env->prev;
  if (ac == 2)
    all = option_setenv_name(buf, all);
  else
    all = option_setenv_name_value(buf, all);
  if (all->nul == 1)
    {
      fprintf(stderr, "%s", ERR_ADD);
      return (do_nul(all));
    }
  while (all->env->next)
    all->env = all->env->next;
  return (all);
}
