/*
** my_put_nbr.c for my_put_nbr in /home/dovan_n//afs
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Wed Oct 10 17:37:39 2012 noel dovan
** Last update Sun Apr 28 11:06:50 2013 noel dovan
*/

#include "my.h"

void	my_put_nbr(int nb)
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
