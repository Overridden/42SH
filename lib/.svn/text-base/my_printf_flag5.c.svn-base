/*
** my_printf_flag5.c for my_printf_flag5 in /home/dovan_n//projets/printf
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Nov 15 08:40:55 2012 noel dovan
** Last update Thu May 23 10:27:32 2013 noel dovan
*/

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "string.h"

int	p2(int nb, int baseto, int nb2, int r)
{
  int	l;
  int	rest;
  char	*res;
  int	rest2;

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
  my_put_hex(res);
  free(res);
  return (r);
}

int	p(int nb, char *base_to, int r)
{
  int	baseto;
  int	nb2;

  baseto = my_strlen(base_to);
  nb2 = nb;
  my_putstr("0x");
  r = r + 3;
  r = p2(nb, baseto, nb2, r);
  return (r);
}

int	f_p(va_list ap, int r)
{
  r = p(va_arg(ap, int), "0123456789abcdef", (r - 2));
  return (r);
}

int	f_m(va_list ap, int r)
{
  ap = ap;
  my_putstr(strerror(errno));
  return (r + 6);
}
