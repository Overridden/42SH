/*
** create_env.c for create_env in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Apr  4 20:08:39 2013 noel dovan
** Last update Fri May  3 10:06:54 2013 noel dovan
*/

#include "data.h"
#include "create.h"
#include "misc.h"

void	my_free_env(t_env *env)
{
  while (env->next)
    env = env->next;
  while (env->prev)
    {
      free(env->name);
      free(env->value);
      env = env->prev;
      free(env->next);
    }
  free(env->name);
  free(env->value);
  free(env);
}

t_env	*fill_env_line(t_env **env, char *ev)
{
  t_env	*elem;

  if (!(elem = malloc(sizeof(*elem))))
    return (NULL);
  if (!(elem->name = get_side_value(ev, SEPARATOR_ENV, LEFT)))
    {
      free(elem);
      return (NULL);
    }
  if (!(elem->value = get_side_value(ev, SEPARATOR_ENV, RIGHT)))
    {
      free(elem->name);
      free(elem);
      return (NULL);
    }
  elem->next = *env;
  elem->prev = NULL;
  if (*env != NULL)
    (*env)->prev = elem;
  *env = elem;
  return (elem);
}

t_env	*create_env(t_env *env, char **ev)
{
  int	i;

  i = -1;
  while (ev[++i])
    if (!(env = fill_env_line(&env, ev[i])))
      return (NULL);
  if (env == NULL)
    return (NULL);
  while (env->next)
    env = env->next;
  return (env);
}
