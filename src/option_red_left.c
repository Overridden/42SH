/*
** option_red_left.c for option_red_left in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 19:02:44 2013 noel dovan
** Last update Tue May 14 19:50:17 2013 noel dovan
*/

#include "data.h"
#include "option_red.h"
#include "misc.h"
#include "exec_buf.h"
#include "create.h"

int	option_red_left_filspere(char *buff, t_all *all, int *pipefd)
{
  if (dup2(pipefd[0], 0) == -1)
    {
      free(buff);
      return (1);
    }
  if (exec_buf(buff, all) == -1)
    {
      free(buff);
      return (1);
    }
  return (0);
}

int	option_red_left_write(char *buff, int *pipefd, int r, int fd)
{
  if (check_correct_red(buff) == 1)
    return (1);
  if (write(pipefd[1], buff, r) == -1)
    {
      free(buff);
      return (1);
    }
  if (close(fd) == -1)
    {
      free(buff);
      return (1);
    }
  return (0);
}

int	option_red_left_filsfils(char *buf, int *pipefd)
{
  char	*buff;
  int	fd;
  int	r;

  if ((buff = get_side_value(buf, '<', 1)) == NULL)
    return (1);
  epur_begin_end(buff);
  epur_for_left_red(buff);
  if ((fd = open(buff, O_RDONLY)) == -1)
    return (1);
  clean_str(buff);
  if (!(buff = realloc(buff, SIZE)))
    return (1);
  if ((r = read(fd, buff, SIZE)) == -1)
    {
      free(buff);
      return (1);
    }
  buff[r] = '\0';
  if (option_red_left_write(buff, pipefd, r, fd) == 1)
    return (1);
  free(buff);
  return (0);
}

int	option_red_left_fils(char *buf, t_all *all, int *pipefd)
{
  pid_t	pid;
  char	*buff;

  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      if (close(pipefd[0]) == -1)
	return (1);
      if (option_red_left_filsfils(buf, pipefd) == 1)
	return (1);
      return (1);
    }
  else
    {
      if (close(pipefd[1]) == -1)
	return (1);
      if ((buff = get_side_value(buf, '<', 0)) == NULL)
	return (1);
      epur_begin_end(buff);
      if (option_red_left_filspere(buff, all, pipefd) == 1)
	return (1);
    }
  free(buff);
  return (0);
}

t_all	*option_red_left(char *buf, t_all *all, char **check)
{
  int	pipefd[2];
  pid_t	pid;

  check = check;
  if (pipe(pipefd) == -1)
    return (do_nul(all));
  if ((pid = fork()) == -1)
    return (do_nul(all));
  if (pid == 0)
    {
      check_red_begin(buf, "<");
      option_red_left_fils(buf, all, pipefd);
      my_printf(" \b");
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
