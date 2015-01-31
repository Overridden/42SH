/*
** my_put_unsign.c for my_put_unsign in /u/all/dovan_n/rendu/lib/my
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sat Nov 10 22:54:12 2012 noel dovan
** Last update Sun Apr 28 11:09:11 2013 noel dovan
*/

#include "my.h"

int	my_put_unsign(unsigned int nb)
{
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + '0');
  return (0);
}
