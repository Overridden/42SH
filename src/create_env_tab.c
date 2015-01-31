/*
** create_env_tab.c for create_env_tab in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 14:46:17 2013 noel dovan
** Last update Wed May 22 10:15:51 2013 noel dovan
*/

#include "data.h"
#include "misc.h"

int	count_tab(char **path)
{
  int	i;

  i = 0;
  while (path[i])
    ++i;
  return (i);
}

int	count_max_lenght(t_env *env)
{
  int	i;

  i = 0;
  while (env->prev)
    {
      if (i < (my_strlen(env->name) + 1 + my_strlen(env->value)))
	i = my_strlen(env->name) + 1 + my_strlen(env->value);
      env = env->prev;
    }
  if (i < (my_strlen(env->name) + 1 + my_strlen(env->value)))
    i = my_strlen(env->name) + 1 + my_strlen(env->value);
  while (env->next)
    env = env->next;
  return (i);
}

int	count_env(t_env *env)
{
  int	i;

  i = 0;
  while (env->prev)
    {
      env = env->prev;
      ++i;
    }
  ++i;
  while (env->next)
    env = env->next;
  return (i);
}

char	*fill_the_tab(char *name, char *value)
{
  char	*buf;

  if (!(buf = malloc(sizeof(*buf) * my_strlen(name) + my_strlen(value) + 2)))
    return (NULL);
  buf = my_strcpy(buf, name);
  buf = my_strcat(buf, S_SEPARATOR_ENV);
  buf = my_strcat(buf, value);
  return (buf);
}

char	**create_env_tab(t_env *env)
{
  char	**ev;
  int	nb;
  int	size;
  int	i;

  nb = count_env(env);
  size = count_max_lenght(env);
  if (!(ev = malloc(sizeof(*ev) * (nb * size + nb))))
    return (NULL);
  i = 0;
  while (env->prev)
    {
      if (!(ev[i++] = fill_the_tab(env->name, env->value)))
	return (NULL);
      env = env->prev;
    }
  if (!(ev[i++] = fill_the_tab(env->name, env->value)))
    return (NULL);
  ev[i] = NULL;
  while (env->next)
    env = env->next;
  return (ev);
}
