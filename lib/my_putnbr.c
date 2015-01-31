/*
** my_putnbr.c for my_putnbr in /u/all/dovan_n/rendu/lib/my
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sat Nov 10 22:37:17 2012 noel dovan
** Last update Sun Apr 28 11:07:00 2013 noel dovan
*/

#include "my.h"

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + '0');
}
