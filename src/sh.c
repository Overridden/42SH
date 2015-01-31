/*
** sh.c for sh in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Apr  4 21:41:52 2013 noel dovan
** Last update Sat May 25 17:09:16 2013 noel dovan
*/

#include "data.h"
#include "sh.h"
#include "misc.h"
#include "call_option.h"
#include "exec_buf.h"

t_all	*check_builtins(char *buf, t_all *all, char **check,
		       t_all *(*fonc[14])(char*, t_all*, char**))
{
  int	i;

  fonc[8] = &option_exit;
  fonc[9] = &option_echo;
  fonc[10] = &option_cd;
  fonc[11] = &option_unsetenv;
  fonc[12] = &option_setenv;
  fonc[13] = &option_env;
  i = 8 - 1;
  while (check[++i])
    if (is_str(buf, check[i]) == 1)
      {
	if ((all = (*fonc[i])(buf, all, check))->nul == 1)
	  return (do_nul(all));
	return (all);
      }
  if ((all->ret = exec_buf(buf, all)) == -1)
    return (do_nul(all));
  all->nul = 0;
  return (all);
}

t_all	*check_buf(char *buf, t_all *all, char **check)
{
  t_all	*(*fonc[14])(char*, t_all*, char**);
  int	i;

  if (!(buf = format_car(all, buf)))
    return (do_nul(all));
  fonc[0] = &option_sc;
  fonc[1] = &option_and;
  fonc[2] = &option_or;
  fonc[3] = &option_pipe;
  fonc[4] = &option_red_leftl;
  fonc[5] = &option_red_left;
  fonc[6] = &option_red_right;
  fonc[7] = &option_red_rightr;
  i = -1;
  while (++i < 8)
    if (is_str(buf, check[i]) == 1)
      {
	if ((all = (*fonc[i])(buf, all, check))->nul == 1)
	  return (do_nul(all));
	return (all);
      }
  if ((all = check_builtins(buf, all, check, fonc))->nul == 1)
    return (do_nul(all));
  return (all);
}

t_all	*sh_read(t_all *all, char **check, char *buf)
{
  int	r;

  while ((r = read(0, buf, SIZE)) > 0)
    {
      buf[r] = '\0';
      all->ret = 0;
      if (isnt_printable(buf) == 0)
      	{
	  epur_str(buf);
	  epur_begin_end(buf);
	  if ((all = check_buf(buf, all, check))->nul == 1)
	    return (do_nul(all));
	}
      clean_str(buf);
      my_printf("%s ", PROMPT);
    }
  return (all);
}

t_all	*sh(t_all *all, char **check)
{
  char	*buf;

  if (!(buf = malloc(sizeof(*buf) * (SIZE + 1))))
    return (do_nul(all));
  my_printf("%s ", PROMPT);
  if ((all = sh_read(all, check, buf))->nul == 1)
    {
      free(buf);
      return (do_nul(all));
    }
  my_printf("exit\n");
  free(buf);
  return (all);
}
