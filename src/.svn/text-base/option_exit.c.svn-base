/*
** option_exit.c for option_exit in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 19:54:47 2013 noel dovan
** Last update Fri May  3 10:06:54 2013 noel dovan
*/

#include "data.h"
#include "option_exit.h"
#include "create.h"

int	option_exit_value(char *buf)
{
  char	*stock_nb;
  int	res;
  int	i;
  int	j;

  i = 5 - 1;
  if (!(stock_nb = malloc(sizeof(*stock_nb) * (my_strlen(buf) + 1))))
    return (NBNULL);
  j = 0;
  while (buf[++i] != '\0')
    {
      if (buf[i] < '0' || buf[i] > '9')
	if (buf[i] != '-')
	  {
	    free(stock_nb);
	    return (NBNULL2);
	  }
      stock_nb[j++] = buf[i];
    }
  stock_nb[j] = '\0';
  res = my_getnbr(stock_nb);
  free(stock_nb);
  return (res);
}

t_all	*option_exit(char *buf, t_all *all, char **check)
{
  check = check;
  if ((all->ret = option_exit_value(buf)) == NBNULL)
    {
      all->ret = -1;
      fprintf(stderr, "%s", ERR_EXIT);
      return (do_nul(all));
    }
  else if (all->ret == NBNULL2)
    {
      fprintf(stderr, "%s", ERR_EXIT_VALUE);
      return (all);
    }
  my_printf("exit\n");
  return (do_nul(all));
}
