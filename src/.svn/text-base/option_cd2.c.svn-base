/*
** option_cd2.c for option_cd2 in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Tue Apr  9 11:49:33 2013 noel dovan
** Last update Fri May  3 10:21:48 2013 noel dovan
*/

#include "data.h"
#include "option_cd.h"
#include "set_pwd.h"

void	option_cd_error(char *cd)
{
  if (access(cd, F_OK) == -1)
    fprintf(stderr, "%s: %s", cd, ERR_CD_NO);
  else if (access(cd, R_OK) == -1)
    fprintf(stderr, "%s: %s", cd, ERR_CD_PERM);
  else
    fprintf(stderr, "%s: %s", cd, ERR_CD_FILE);
}

t_all	*option_cd_exec(char *cd, t_all *all, char **check)
{
  while (all->env->next)
    all->env = all->env->next;
  if ((all = set_oldpwd(all, check))->nul == 1)
    {
      free(cd);
      return (do_nul(all));
    }
  if (chdir(cd) == -1)
    option_cd_error(cd);
  if ((all = set_pwd(all, check))->nul == 1)
    {
      free(cd);
      return (do_nul(all));
    }
  while (all->env->next)
    all->env = all->env->next;
  return (all);
}
