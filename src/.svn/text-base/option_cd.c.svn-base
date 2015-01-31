/*
** option_cd.c for option_cd in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Apr  7 22:05:42 2013 noel dovan
** Last update Mon Apr 29 13:36:50 2013 noel dovan
*/

#include "data.h"
#include "option_cd.h"
#include "misc.h"

t_all	*option_cd_buf(char *buf, t_all *all, char **check)
{
  char	*cd;
  int	i;

  if (!(cd = get_side_value(buf, ' ', RIGHT)))
    {
      fprintf(stderr, "%s: %s", buf, ERR_CD_WRONG);
      return (all);
    }
  i = -1;
  while (cd[++i] != '\0')
      if (cd[i] == ' ')
	{
	  if (cd[i + 1] != '\0')
	    {
	      fprintf(stderr, "%s", ERR_CD_ARG);
	      free(cd);
	      return (all);
	    }
	  else
	    cd[i] = '\0';
	}
  if ((all = option_cd_exec(cd, all, check))->nul == 1)
    return (do_nul(all));
  free(cd);
  return (all);
}

t_all	*option_cd_hyphen(t_all *all, char **check)
{
  char	*cd;

  check = check;
  if ((all = seek_name_env(all, "OLDPWD"))->nul == 1)
    {
      fprintf(stderr, "%s", ERR_CD_HYPHEN);
      all->nul = 0;
      return (all);
    }
  if (!(cd = my_strdup(all->env->value)))
    return (do_nul(all));
  if ((all = option_cd_exec(cd, all, check))->nul == 1)
    return (do_nul(all));
  free(cd);
  return (all);
}

t_all	*option_cd_back(t_all *all, char **check)
{
  char	*cd;

  check = check;
  if (!(cd = my_strdup("..")))
    return (do_nul(all));
  if ((all = option_cd_exec(cd, all, check))->nul == 1)
    return (do_nul(all));
  free(cd);
  return (all);
}

t_all	*option_cd_home(t_all *all, char **check)
{
  char	*cd;

  check = check;
  if ((all = seek_name_env(all, "HOME"))->nul == 1)
    {
      fprintf(stderr, "%s", ERR_CD_HOME);
      all->nul = 0;
      return (all);
    }
  if (!(cd = my_strdup(all->env->value)))
    return (do_nul(all));
  if ((all = option_cd_exec(cd, all, check))->nul == 1)
    return (do_nul(all));
  free(cd);
  return (all);
}

t_all	*option_cd(char *buf, t_all *all, char **check)
{
  if (buf[2] == '\0' || buf[3] == '\0')
    {
      if ((all = option_cd_home(all, check))->nul == 1)
	return (do_nul(all));
    }
  else if (buf[2] == '.' && buf[3] == '.' && buf[4] == '\0')
    {
      if ((all = option_cd_back(all, check))->nul == 1)
	return (do_nul(all));
    }
  else if (buf[2] == ' ' && buf[3] == '-' && buf[4] == '\0')
    {
      if ((all = option_cd_hyphen(all, check))->nul == 1)
	return (do_nul(all));
    }
  else
    {
      if ((all = option_cd_buf(buf, all, check))->nul == 1)
	return (do_nul(all));
    }
  return (all);
}
