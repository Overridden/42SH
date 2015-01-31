/*
** set_pwd.c for set_pwd in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Mon Apr  8 16:49:53 2013 noel dovan
** Last update Fri May  3 10:06:50 2013 noel dovan
*/

#include "data.h"
#include "set_pwd.h"
#include "misc.h"
#include "sh.h"
#include "option_env.h"
#include "create.h"

t_all	*set_pwd_set(t_all *all, char **check, char *pwd)
{
  char	*setenv;

  if (already_in(all->env, "PWD") == 1)
    if ((all = check_buf("unsetenv PWD", all, check))->nul == 1)
      return (do_nul(all));
  if (!(setenv = malloc(sizeof(*setenv) * (12 + my_strlen(pwd)))))
    return (do_nul(all));
  setenv[0] = '\0';
  setenv = my_strcpy(setenv, "setenv PWD ");
  setenv = my_strcat(setenv,  pwd);
  if ((all = check_buf(setenv, all, check))->nul == 1)
    {
      free(setenv);
      return (do_nul(all));
    }
  free(setenv);
  return (all);
}

t_all	*set_pwd_read(t_all *all, char **check, int *pipefd)
{
  char	*pwd;
  int	r;

  if (!(pwd = malloc(sizeof(*pwd) * SIZE)))
    return (do_nul(all));
  if ((r = read(pipefd[0], pwd, SIZE)) < 0)
    {
      free(pwd);
      return (do_nul(all));
    }
  pwd[r - 1] = '\0';
  if ((all = set_pwd_set(all, check, pwd))->nul == 1)
    {
      free(pwd);
      return (do_nul(all));
    }
  free(pwd);
  return (all);
}

t_all	*set_pwd_fork(t_all *all, char **check, int *pipefd, pid_t pid)
{
  if (pid == 0)
    {
      if (close(pipefd[0]) == -1)
	return (do_nul(all));
      if (dup2(pipefd[1], 1) == -1)
	return (do_nul(all));
      all = check_buf("pwd", all, check);
      return (do_nul(all));
    }
  else
    {
      if (close(pipefd[1]) == -1)
	return (do_nul(all));
      if (wait(0) == -1)
	return (do_nul(all));
      if (dup2(1, pipefd[1]) == -1)
	return (do_nul(all));
      if ((all = set_pwd_read(all, check, pipefd))->nul == 1)
	return (do_nul(all));
    }
  return (all);
}

t_all	*set_pwd(t_all *all, char **check)
{
  int	pipefd[2];
  pid_t	pid;

  if (pipe(pipefd) == -1)
    return (do_nul(all));
  if ((pid = fork()) == -1)
    return (do_nul(all));
  if ((all = set_pwd_fork(all, check, pipefd, pid))->nul == 1)
    return (do_nul(all));
  return (all);
}
