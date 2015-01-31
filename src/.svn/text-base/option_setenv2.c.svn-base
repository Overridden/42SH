/*
** option_setenv2.c for option_setenv2 in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Apr  7 17:14:16 2013 noel dovan
** Last update Mon Apr 29 13:42:43 2013 noel dovan
*/

#include "data.h"
#include "option_env.h"
#include "misc.h"
#include "exec_buf.h"

t_env	*option_setenv_fill(t_env **env, char *name, char *value)
{
  t_env	*elem;

  if (!(elem = malloc(sizeof(*elem))))
    return (NULL);
  if (value != NULL)
    {
      if (!(elem->value = my_strdup(value)))
	return (NULL);
    }
  else
    if (!(elem->value = my_strdup("\0")))
      return (NULL);
  if (!(elem->name = my_strdup(name)))
    {
      free(elem);
      free(elem->value);
      return (NULL);
    }
  elem->next = *env;
  elem->prev = NULL;
  if (*env != NULL)
    (*env)->prev = elem;
  *env = elem;
  return (elem);
}

int	option_setenv_check(char *buf, t_all *all)
{
  if (count_car(buf, ' ') - 1 > 2)
    {
      fprintf(stderr, "%s", ERR_SETENV);
      return (-1);
    }
  else if (count_car(buf, ' ') - 1 == 0)
    {
      if (exec_buf("env", all) == -1)
	return (-2);
      return (-1);
    }
  return (count_car(buf, ' '));
}
