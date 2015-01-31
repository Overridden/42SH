/*
** my_printf_flag.c for my_printf_flag in /home/dovan_n//projets/printf
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Nov 15 08:39:42 2012 noel dovan
** Last update Thu May 23 10:31:29 2013 noel dovan
*/

#include <stdlib.h>
#include "string.h"

int	s(char *str, int r)
{
  int	j;

  j = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      r = r + 6;
    }
  else
    while (str[j] != '\0')
      {
	my_putchar(str[j]);
	++j;
	++r;
      }
  return (r);
}

int	cha(char c, int r)
{
  (c == '\0' ? 0 : my_putchar(c));
  ++r;
  return (r);
}

int	di(int nb, int r)
{
  if (nb >= -2147483647 && nb <= 2147483647)
    {
      my_put_nbr(nb);
      r = my_nbrlen(nb, r);
    }
  else if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      r = r + 11;
    }
  else
    {
      my_put_nbr(0);
      ++r;
    }
  return (r);
}

int	u(unsigned int unb, int r)
{
  if (unb <= 4294967294)
    {
      my_put_unsign(unb);
      r = my_unsignlen(unb, r);
    }
  else
    {
      my_put_nbr(0);
      ++r;
    }
  return (r);
}

int	o(unsigned int nb, char *base_to, int r)
{
  int		baseto;
  unsigned int	nb2;

  baseto = my_strlen(base_to);
  nb2 = nb;
  r = dec_to_less(nb, baseto, nb2, r);
  return (r);
}
