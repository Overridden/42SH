/*
** option_sc.c for option_sc in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 01:23:36 2013 noel dovan
** Last update Fri May  3 10:06:52 2013 noel dovan
*/

#include "data.h"
#include "option_sc.h"
#include "sh.h"
#include "misc.h"
#include "create.h"
#include "option_cd.h"

t_all	*option_sc_exec(char *buf, t_all *all, char **check)
{
  char	*buff;

  if ((buff = get_side_value(buf, SC, 0)) == NULL)
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

t_all	*option_sc_resend(char *buf, t_all *all, char **check, int cdflag)
{
  char	*buff;

  if (cdflag == 0)
    if (wait(0) == -1)
      return (do_nul(all));
  if ((buff = get_side_value(buf, SC, 1)) == NULL)
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

t_all	*option_sc_cd(char *buf, t_all *all, char **check)
{
  if ((all = option_sc_exec(buf, all, check))->nul == 1)
    return (do_nul(all));
  if ((all = option_sc_resend(buf, all, check, 1))->nul == 1)
    return (do_nul(all));
  return (all);
}

t_all	*option_sc(char *buf, t_all *all, char **check)
{
  pid_t	pid;

  if (is_only_sc(buf) == 1)
    return (all);
  if (buf[0] == 'c' && buf[1] == 'd')
    {
      if ((all = option_sc_cd(buf, all, check))->nul == 1)
	return (do_nul(all));
    }
  else
    {
      if ((pid = fork()) == -1)
	return (do_nul(all));
      if (pid == 0)
	{
	  option_sc_exec(buf, all, check);
	  return (do_nul(all));
	}
      else
	if ((all = option_sc_resend(buf, all, check, 0))->nul == 1)
	  return (do_nul(all));
    }
  return (all);
}
