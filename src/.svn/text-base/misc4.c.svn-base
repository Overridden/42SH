/*
** misc4.c for misc4 in /home/dovan_n//svn/42sh-2017-nguye_1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri May  3 13:39:05 2013 noel dovan
** Last update Sun May 26 06:08:31 2013 noel dovan
*/

#include "misc.h"

char	*get_the_variable(char *buf, int i)
{
  char	*variable;
  int	j;

  if (!(variable = malloc(sizeof(*buf) * (my_strlen(buf) + 1))))
    {
      fprintf(stderr, "%s", ERR_MALLOC);
      return (NULL);
    }
  j = 0;
  while (buf[i] != '\0' && buf[i] != ' ')
    variable[j++] = buf[i++];
  variable[j] = '\0';
  return (variable);
}

char	*format_car_variable_cat(t_all *all, char *buf, int i, int k)
{
  char	*buff;
  int	j;

  j = 0;
  if (!(buff = malloc(sizeof(*buf) * (my_strlen(buf) + 1))))
    {
      fprintf(stderr, "%s", ERR_MALLOC);
      return (NULL);
    }
  while (buf[k] != '\0')
    buff[j++] = buf[k++];
  buff[j] = '\0';
  j = -1;
  while (all->env->value[++j] != '\0')
    buf[i++] = all->env->value[j];
  while (all->env->next)
    all->env = all->env->next;
  buf[i] = '\0';
  buf = my_strcat(buf, buff);
  return (buf);
}

char	*format_car_variable(t_all *all, char *buf, int i)
{
  char	*variable;
  int	k;

  k = i - 1;
  if (!(variable = get_the_variable(buf, i + 1)))
    return (NULL);
  if ((all = seek_name_env(all, variable))->nul == 1)
    {
      all->nul = 0;
      fprintf(stderr, "%s: %s", variable, ERR_VARIABLE);
      return (buf);
    }
  while (buf[++k] != '\0' && buf[k] != ' ');
  if (!(buf = format_car_variable_cat(all, buf, i, k)))
    return (NULL);
  return (buf);
}

char	*format_car_home(t_all *all, char *buf, int i)
{
  char	*buff;
  int	j;

  j = -1;
  if ((all = seek_name_env(all, "HOME"))->nul == 1)
    {
      all->nul = 0;
      fprintf(stderr, "%s: %s", "HOME", ERR_VARIABLE);
      return (buf);
    }
  if (!(buff = get_side_value(buf, TILD, RIGHT)))
    return (NULL);
  while (all->env->value[++j] != '\0')
    buf[i++] = all->env->value[j];
  while (all->env->next)
    all->env = all->env->next;
  buf[i] = '\0';
  buf = my_strcat(buf, buff);
  return (buf);
}

char	*format_car(t_all *all, char *buf)
{
  int	i;

  i = -1;
  while (buf[++i] != '\0')
    {
      if (buf[i] == TILD)
	{
	  if (buf[i + 1] == ' ' || buf[i + 1] == '\0')
	    {
	      if (!(buf = format_car_home(all, buf, i)))
		return (NULL);
	    }
	  else
	    if (!(buf = format_car_tilde(buf, i)))
	      return (NULL);
	}
      else if (buf[i] == VARIABLE)
	if ((buf[i + 1] >= 'A' && buf[i + 1] <= 'Z') ||
	    (buf[i + 1] >= 'a' && buf[i + 1] <= 'z'))
	  if (!(buf = format_car_variable(all, buf, i)))
	    return (NULL);
    }
  return (buf);
}
