/*
** option_or.c for option_or in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Apr 14 20:16:35 2013 noel dovan
** Last update Wed May  8 08:23:10 2013 noel dovan
*/

#include "data.h"
#include "option_or.h"
#include "misc.h"
#include "sh.h"

t_all	*option_or_exec_right(char *buf, t_all *all, char **check)
{
  char	*buff;

  if (!(buff = get_side_value(buf, OR, RIGHT)))
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

t_all	*option_or_exec_left(char *buf, t_all *all, char **check)
{
  char	*buff;

  if (!(buff = get_side_value(buf, OR, LEFT)))
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

t_all	*option_or(char *buf, t_all *all, char **check)
{
  all = option_or_exec_left(buf, all, check);
  if (all->ret != 0)
    {
      if ((all = option_or_exec_right(buf, all, check))->nul == 1 ||
	  all->ret != 0)
	return (all);
      return (do_nul(all));
    }
  return (all);
}
