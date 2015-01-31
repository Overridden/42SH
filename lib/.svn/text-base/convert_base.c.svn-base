/*
** convert_base.c for convert_base in /home/dovan_n//zero/convert
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Dec  2 17:21:52 2012 noel dovan
** Last update Thu May 23 10:30:30 2013 noel dovan
*/

#include <stdlib.h>
#include "my.h"

int	dec_to_base_count(int nb, int baseto)
{
  int	l;

  l = 0;
  while (nb > 0)
    {
      nb = nb / baseto;
      ++l;
    }
  return (l);
}

char	*dec_to_base(int nb, int baseto, char *base_to)
{
  int	l;
  int	rest;
  char	*res;

  rest = 0;
  l = dec_to_base_count(nb, baseto);
  if ((res = malloc(sizeof(*res) * nb)) == NULL)
    return (NULL);
  while (nb > 0)
    {
      rest = nb % baseto;
      nb = nb / baseto;
      res[l - 1] = base_to[rest];
      --l;
    }
  return (res);
}

int	base_to_dec(int nb, char *nbr, int basefrom)
{
  int	res;
  int	x;
  int	b;

  nb = nb;
  res = 0;
  x = my_strlen(nbr) - 1;
  b = 0;
  while (x > -1)
    res = (nbr[x--] - 48) * my_power_it(basefrom, b++) + res;
  return (res);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  char	*str;
  int	basefrom;
  int	baseto;
  int	nb;

  basefrom = my_strlen(base_from);
  baseto = my_strlen(base_to);
  nb = my_getnbr(nbr);
  if (basefrom == 10)
    str = dec_to_base(nb, baseto, base_to);
  else
    {
      nb = base_to_dec(nb, nbr, basefrom);
      str = dec_to_base(nb, baseto, base_to);
    }
  return (str);
}
