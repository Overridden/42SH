/*
** misc3.c for misc3 in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 01:29:38 2013 noel dovan
** Last update Wed May 22 10:14:44 2013 noel dovan
*/

#include "data.h"
#include "misc.h"

char	*get_side_value_right(char *line, char sep, char *buf)
{
  int	i;
  int	j;

  i = -1;
  while (line[++i] != sep)
    if (line[i] == '\0')
      return (NULL);
  while (line[i] == sep)
    ++i;
  j = 0;
  while (line[i] != '\0')
    buf[j++] = line[i++];
  buf[j] = '\0';
  return (buf);
}

char	*get_side_value_left(char *line, char sep, char *buf)
{
  int	i;

  i = -1;
  while (line[++i] != sep)
    {
      if (line[i] == '\0')
	return (NULL);
      buf[i] = line[i];
    }
  buf[i] = '\0';
  return (buf);
}

char	*get_side_value(char *line, char sep, int flag)
{
  char	*buf;

  if (!(buf = malloc(sizeof(*buf) * (my_strlen(line) + 1))))
    {
      fprintf(stderr, "%s", ERR_MALLOC);
      return (NULL);
    }
  if (flag == LEFT)
    {
      if (!(buf = get_side_value_left(line, sep, buf)))
	{
	  free(buf);
	  return (NULL);
	}
    }
  else
    if (!(buf = get_side_value_right(line, sep, buf)))
      {
	free(buf);
	return (NULL);
      }
  return (buf);
}

t_all	*seek_name_env(t_all *all, char *name)
{
  while (all->env->next)
    all->env = all->env->next;
  while (all->env->prev)
    {
      if (my_strcmp(all->env->name, name) == 0)
	return (all);
      all->env = all->env->prev;
    }
  if (my_strcmp(all->env->name, name) == 0)
    return (all);
  while (all->env->next)
    all->env = all->env->next;
  return (do_nul(all));
}
