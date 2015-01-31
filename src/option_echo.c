/*
** option_echo.c for option_echo in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 20:01:07 2013 noel dovan
** Last update Thu May 16 19:18:44 2013 noel dovan
*/

#include "data.h"
#include "option_echo.h"
#include "init_tab.h"
#include "exec_buf.h"

t_all	*option_echo(char *buf, t_all *all, char **check)
{
  char	**tab;
  int	i;
  int	n;

  check = check;
  if (buf[5] == '-' && buf[6] == 'n' && buf[7] == ' ')
    n = 1;
  else
    n = 0;
  if (!(tab = init_tab(buf, SEPARATOR_BUF)))
    return (do_nul(all));
  if (n == 1)
    i = 1;
  else
    i = 0;
  while (tab[++i] != NULL)
    {
      my_putstr(tab[i]);
      if (tab[i + 1] != NULL)
	my_putchar(' ');
    }
  if (n == 0)
    my_putchar('\n');
  my_free_tab(tab);
  return (all);
}
