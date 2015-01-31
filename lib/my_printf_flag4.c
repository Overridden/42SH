/*
** my_printf_flag4.c for my_printf_flag4 in /home/dovan_n//projets/printf
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Nov 15 08:40:37 2012 noel dovan
** Last update Thu May 23 10:28:01 2013 noel dovan
*/

#include <stdlib.h>
#include "string.h"

void	my_putstr_hex(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0' && j != 8)
    {
      my_putchar(str[i]);
      ++i;
      ++j;
    }
}

int	my_put_hex_cap(char *str)
{
  char	hex[6] = ":;<=>?";
  char	cor[6] = "ABCDEF";
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i] != '\0')
    {
      while (n != 6)
	{
	  if (str[i] == hex[n])
	    str[i] = cor[n];
	  ++n;
	}
      n = 0;
      ++i;
    }
  my_putstr_hex(str);
  return (0);
}

int		dec_to_hex_cap(unsigned int nb, int baseto,
			       unsigned int nb2, int r)
{
  int		l;
  unsigned int	rest;
  char		*res;
  unsigned int	rest2;

  l = 0;
  rest = 0;
  rest2 = 0;
  l = dec_to_count(nb2, rest2, baseto, l);
  res = malloc(sizeof(l));
  if (res == NULL)
    return (1);
  while (nb > 0)
    {
      rest = nb % baseto;
      nb = nb / baseto;
      res[l - 1] = rest + 48;
      --l;
      ++r;
    }
  my_put_hex_cap(res);
  free(res);
  return (r);
}
int	x_cap(unsigned int nb, char *base_to, int r)
{
  int		baseto;
  unsigned int	nb2;

  baseto = my_strlen(base_to);
  nb2 = nb;
  r = dec_to_hex_cap(nb, baseto, nb2, r);
  return (r);
}
