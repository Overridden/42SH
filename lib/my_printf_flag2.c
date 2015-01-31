/*
** my_printf_flag2.c for my_printf_flag2 in /home/dovan_n//projets/printf
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Nov 15 08:39:07 2012 noel dovan
** Last update Thu May 23 10:28:40 2013 noel dovan
*/

#include <stdlib.h>
#include "string.h"

int	my_put_octal(char *str)
{
  int	x;

  x = my_strlen(str);
  if (x == 1)
    {
      my_putchar('0');
      my_putchar('0');
      my_putstr(str);
    }
  else if (x == 2)
    {
      my_putchar('0');
      my_putstr(str);
    }
  else
    {
      my_putstr(str);
    }
  return (0);
}

int		dec_to_octal(unsigned int nb, int baseto,
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
  res = malloc(sizeof(l) + 1);
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
  my_put_octal(res);
  free(res);
  return (r + 3);
}

int	s_octal(char *str, int r)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      r = r + 6;
    }
  else
    while (str[i] != '\0')
      {
	if (str[i] < 32 || str[i] >= 127)
	  {
	    my_putchar('\\');
	    r = dec_to_octal(str[i], 8, str[i], r);
	    ++i;
	  }
	my_putchar(str[i]);
	++i;
	++r;

      }
  return (r);
}

int	my_nbrlen(int nb, int r)
{
  if (nb < 0)
    my_nbrlen(nb * -1, r + 1);
  else if (nb >= 10)
    my_nbrlen(nb / 10, r + 1);
  else
    return (r + 1);
  return (r + 1);
}

int	my_unsignlen(unsigned int nb, int r)
{
  if (nb >= 10)
    my_unsignlen(nb / 10, r + 1);
  else
    return (r + 1);
  return (r + 1);
}
