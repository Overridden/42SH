/*
** my_putnbr_base.c for my_putnbr_base in /u/all/dovan_n/rendu/lib/my
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Mon Nov 26 15:55:43 2012 noel dovan
** Last update Sun Apr 28 11:07:10 2013 noel dovan
*/

#include "my.h"

void	my_putnbr_base(int nb, char *base_to)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb >= my_strlen(base_to))
    {
      my_putnbr_base(nb / my_strlen(base_to), base_to);
      my_putnbr_base(nb % my_strlen(base_to), base_to);
    }
  else
    my_putchar(base_to[nb]);
}
