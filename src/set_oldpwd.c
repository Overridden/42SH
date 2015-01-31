/*
** set_oldpwd.c for set_oldpwd in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Apr  7 22:33:24 2013 noel dovan
** Last update Fri May  3 10:21:47 2013 noel dovan
*/

#include "data.h"
#include "set_pwd.h"
#include "misc.h"
#include "sh.h"
#include "create.h"

t_all	*set_oldpwd_set(t_all *all, char **check, char *pwd)
{
  char	*setenv;

  if (already_in(all->env, "OLDPWD") == 1)
    if ((all = check_buf("unsetenv OLDPWD", all, check))->nul == 1)
      return (do_nul(all));
  if (!(setenv = malloc(sizeof(*setenv) * (16 + my_strlen(pwd)))))
    return (do_nul(all));
  setenv[0] = '\0';
  setenv = my_strcpy(setenv, "setenv OLDPWD ");
  setenv = my_strcat(setenv, pwd);
  if ((all = check_buf(setenv, all, check))->nul == 1)
    {
      free(setenv);
      return (do_nul(all));
    }
  free(setenv);
  return (all);
}

t_all	*set_oldpwd(t_all *all, char **check)
{
  char	*pwd;

  if ((all = seek_name_env(all, "PWD"))->nul == 1)
    return (do_nul(all));
  if (!(pwd = my_strdup(all->env->value)))
    return (do_nul(all));
  if ((all = set_oldpwd_set(all, check, pwd))->nul == 1)
    {
      free(pwd);
      return (do_nul(all));
    }
  free(pwd);
  return (all);
}
