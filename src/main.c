/*
** main.c for main in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Apr  4 21:40:59 2013 noel dovan
** Last update Thu May 16 20:09:50 2013 noel dovan
*/

#include "data.h"
#include "main.h"
#include "create.h"
#include "sh.h"

void	ctrl_c(int sig)
{
  sig = sig;
  my_printf("\n%s ", PROMPT);
}

t_env	*init_sh(int ac, char **ev)
{
  t_env	*env;

  if (ac > 1)
    {
      fprintf(stderr, "%s", ERR_USE);
      return (NULL);
    }
  if (signal(SIGINT, &ctrl_c) == SIG_ERR)
    {
      fprintf(stderr, "%s", ERR_SIG);
      return (NULL);
    }
  env = NULL;
  if (!(env = create_env(env, ev)))
    {
      fprintf(stderr, "%s", ERR_ENV);
      return (NULL);
    }
  return (env);
}

int	exec_sh(t_all *all, char **check)
{
  int	ret;

  if ((all = sh(all, check))->nul == 1)
    {
      my_free_check(check);
      ret = all->ret;
      my_free_env(all->env);
      free(all);
      return (ret);
    }
  my_free_check(check);
  my_free_env(all->env);
  free(all);
  return (0);
}

int	main(int ac, char **av, char **ev)
{
  char	**check;
  t_all	*all;

  av = av;
  check = NULL;
  if (!(all = malloc(sizeof(*all))))
    return (1);
  all->nul = 0;
  if (!(check = create_check(check)))
    {
      free(all);
      return (1);
    }
  if (!(all->env = init_sh(ac, ev)))
    {
      my_free_check(check);
      free(all);
      return (1);
    }
  return (exec_sh(all, check));
}
