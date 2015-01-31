/*
** exec_buf.c for exec_buf in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 13:40:02 2013 noel dovan
** Last update Thu May 30 21:55:07 2013 alexandre1 nguyen
*/

#include "data.h"
#include "exec_buf.h"
#include "main.h"
#include "misc.h"
#include "init_tab.h"
#include "create.h"
#include "option_signal.h"

int	exec_buf_execpath(char **av, t_env *env)
{
  char	**ev;

  while (env->next)
    env = env->next;
  if (!(ev = create_env_tab(env)))
    return (1);
  if (execve(av[0], av, ev) == -1)
    {
      fprintf(stderr, "%s: %s", av[0], ERR_EXEC);
      return (1);
    }
  return (0);
}

int	exec_buf_exec(char **path, char **av, char **ev, char *filename)
{
  int	i;

  i = 0;
  while (execve(filename, av, ev) == -1)
    {
      if (i == (count_tab(path) - 1))
	{
	  my_free_tab(path);
	  my_free_tab(ev);
	  fprintf(stderr, "%s: %s", av[0], ERR_EXEC);
	  free(filename);
	  return (1);
	}
      ++i;
      clean_str(filename);
      if (!(filename = realloc(filename, sizeof(*filename) *
			       (my_strlen(path[i]) + 2 + my_strlen(av[0])))))
	{
	  free(filename);
	  return (1);
	}
      filename = my_strcpy(filename, path[i]);
      filename = my_strcat(my_strcat(filename, "/"), av[0]);
    }
  return (0);
}

int	exec_buf_init(char **av, t_env *env, t_all *all)
{
  char	*filename;
  char	**path;
  char	**ev;

  all = seek_name_env(all, "PATH");
  if (!(path = init_tab(all->env->value, SEPARATOR_PATH)))
    return (1);
  if (!(filename = malloc(sizeof(*filename) *
			  (my_strlen(path[0]) + 2 + my_strlen(av[0])))))
    return (1);
  filename = my_strcpy(filename, path[0]);
  filename = my_strcat(my_strcat(filename, "/"), av[0]);
  while (env->next)
    env = env->next;
  if (!(ev = create_env_tab(env)))
    {
      my_free_tab(path);
      return (1);
    }
  if (exec_buf_exec(path, av, ev, filename) == 1)
    return (1);
  return (0);
}

int	exec_buf_fork(char **av, t_env *env, t_all *all)
{
  pid_t	f;
  int	status;

  if ((f = fork()) == -1)
    return (-1);
  if (f == 0)
    {
      if (my_strcmp(av[0], "kill") == 0 || my_strcmp(av[0], "/bin/kill") == 0)
	if (setpgid(getpid(), 0) == -1)
	  return (-1);
      if (av[0][0] == '.' || av[0][0] == '/')
	exec_buf_execpath(av, env);
      else
	exec_buf_init(av, env, all);
      return (-1);
    }
  else
    {
      if (wait(&status) == -1)
  	return (-1);
      option_signal(status);
    }
  return (status);
}

int	exec_buf(char *buf, t_all *all)
{
  char	**av;
  int	ret;

  ret = 0;
  if (buf[0] == '\0')
    return (0);
  if (!(av = init_tab(buf, SEPARATOR_BUF)))
    return (0);
  if ((ret = exec_buf_fork(av, all->env, all)) == -1)
    {
      my_free_tab(av);
      return (-1);
    }
  my_free_tab(av);
  return (ret);
}
