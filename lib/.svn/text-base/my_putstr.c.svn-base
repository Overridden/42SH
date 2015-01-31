/*
** my_putstr.c for my_putstr in /home/dovan_n//afs/j4local
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Oct  4 19:45:52 2012 noel dovan
** Last update Sun Apr 28 11:08:35 2013 noel dovan
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}
