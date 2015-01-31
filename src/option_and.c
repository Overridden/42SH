/*
** option_and.c for option_and in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr 12 18:57:15 2013 noel dovan
** Last update Mon May  6 18:32:17 2013 noel dovan
*/

#include "data.h"
#include "option_and.h"
#include "misc.h"
#include "sh.h"

t_all	*option_and_exec_right(char *buf, t_all *all, char **check)
{
  char	*buff;

  if (!(buff = get_side_value(buf, AND, RIGHT)))
    return (do_nul(all));
  epur_begin_end(buff);
  if ((all = check_buf(buff, all, check))->nul == 1)
    {
      free(buff);
      return (do_nul(all));
    }
  free(buff);
  return (all);
}

t_all	*option_and_exec_left(char *buf, t_all *all, char **check)
{
  char	*buff;

  if (!(buff = get_side_value(buf, AND, LEFT)))
    return (do_nul(all));
  epur_begin_end(buff);
  if ((all = check_buf(buff, all, check))->nul == 1)
    {
      free(buff);
      return (do_nul(all));
    }
  free(buff);
  return (all);
}

t_all	*option_and(char *buf, t_all *all, char **check)
{
  if ((all = option_and_exec_left(buf, all, check))->nul == 1 ||
      all->ret != 0)
    return (all);
  if ((all = option_and_exec_right(buf, all, check))->nul == 1 ||
      all->ret != 0)
    return (all);
  return (all);
}
