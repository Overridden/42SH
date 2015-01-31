/*
** option_pipe.c for option_pipe in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 16:04:00 2013 noel dovan
** Last update Fri May 31 05:31:49 2013 alexandre1 nguyen
*/

#include "data.h"
#include "option_pipe.h"
#include "misc.h"
#include "sh.h"
#include "create.h"

int	option_pipe_filsfils(char *buf, t_all *all, int *pipefd, char **check)
{
  char	*buff;

  if (close(pipefd[0]) == -1)
    return (1);
  if ((buff = get_side_value(buf, PIPE, LEFT)) == NULL)
    return (1);
  epur_begin_end(buff);
  if (dup2(pipefd[1], 1) == -1)
    {
      free(buff);
      return (1);
    }
  if ((all = check_buf(buff, all, check))->nul == 1)
    {
      free(buff);
      return (1);
    }
  free(buff);
  return (0);
}

int	option_pipe_fils(char *buf, t_all *all, int *pipefd, char **check)
{
  pid_t	pid;
  char	*buff;

  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      if (option_pipe_filsfils(buf, all, pipefd, check) == 1)
	return (1);
      return (1);
    }
  else
    {
      if (wait(0) == -1)
	return (1);
      if (close(pipefd[1]) == -1)
	return (1);
      if ((buff = get_side_value(buf, PIPE, RIGHT)) == NULL)
	return (1);
      epur_begin_end(buff);
      if (dup2(pipefd[0], 0) == -1)
	return (1);
      if ((all = check_buf(buff, all, check))->nul == 1)
	return (1);
    }
  free(buff);
  return (0);
}

t_all	*option_pipe(char *buf, t_all *all, char **check)
{
  int	pipefd[2];
  pid_t	pid;

  if (pipe(pipefd) == -1)
    return (do_nul(all));
  if ((pid = fork()) == -1)
    return (do_nul(all));
  if (pid == 0)
    {
      option_pipe_fils(buf, all, pipefd, check);
      return (do_nul(all));
    }
  else
    {
      if (wait(0) == -1)
	return (do_nul(all));
      if (dup2(1, pipefd[1]) == -1)
	return (do_nul(all));
      if (dup2(0, pipefd[0]) == -1)
	return (do_nul(all));
    }
  return (all);
}
