/*
** option_unsetenv.c for option_unsetenv in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Apr  7 17:27:56 2013 noel dovan
** Last update Thu May 23 10:21:53 2013 noel dovan
*/

#include "data.h"
#include "option_env.h"
#include "misc.h"

t_env	*option_unsetenv_rm_cas(t_env *env)
{
  t_env	*tmp;

  free(env->name);
  free(env->value);
  if (env->prev && env->next)
    {
      tmp = env->next;
      env = env->prev;
      free(tmp->prev);
      tmp->prev = env;
      env->next = tmp;
    }
  else if (env->prev && !env->next)
    {
      env = env->prev;
      free(env->next);
      env->next = NULL;
    }
  else
    {
      env = env->next;
      free(env->prev);
      env->prev = NULL;
    }
  return (env);
}

t_env	*option_unsetenv_rm(t_env *env, char *name)
{
  while (env->next)
    env = env->next;
  while (env)
    {
      if (my_strcmp(env->name, name) == 0)
	{
	  env = option_unsetenv_rm_cas(env);
	  while (env->next)
	    env = env->next;
	  return (env);
	}
      env = env->prev;
    }
  return (env);
}

t_env	*option_unsetenv_parse(char *buf, t_env *env, int ac)
{
  char	*name;
  int	i;
  int	j;

  if (!(name = malloc(sizeof(*name) * my_strlen(buf))))
    return (NULL);
  i = -1;
  while (buf[++i] != ' ')
    ;
  while (ac-- > 1)
    {
      j = 0;
      while (buf[++i] != ' ' && buf[i] != '\0')
	name[j++] = buf[i];
      name[j] = '\0';
      if (already_in(env, name) == 0)
	fprintf(stderr, "%s: %s", name, ERR_UNSET_NO);
      else
	env = option_unsetenv_rm(env, name);
    }
  free(name);
  return (env);
}

int	option_unsetenv_check(char *buf)
{
  if (count_car(buf, ' ') - 1 == 0)
    {
      fprintf(stderr, "%s", ERR_UNSET_ARG);
      return (-1);
    }
  return (count_car(buf, ' '));
}

t_all	*option_unsetenv(char *buf, t_all *all, char **check)
{
  int	ac;

  check = check;
  if ((ac = option_unsetenv_check(buf)) == -1)
    return (all);
  if (!(all->env = option_unsetenv_parse(buf, all->env, ac)))
    return (do_nul(all));
  return (all);
}
