/*
** my_putchar.c for my_putchar in /home/dovan_n//afs
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Wed Oct 10 10:56:31 2012 noel dovan
** Last update Sun Apr 28 11:02:35 2013 noel dovan
*/

#include <unistd.h>

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (-1);
  return (0);
}
