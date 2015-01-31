/*
** my_printf_fonc.c for my_printf_fonc in /home/dovan_n//projets/printf
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Nov 15 08:41:27 2012 noel dovan
** Last update Sun Apr 28 11:06:37 2013 noel dovan
*/

#include <stdlib.h>
#include <stdarg.h>
#include "string.h"

int	f_percent(va_list ap, int r)
{
  ap = ap;
  my_putchar('%');
  return (r);
}

int	f_s(va_list ap, int r)
{
  r = s(va_arg(ap, char*), r - 1);
  return (r);
}

int	f_cha(va_list ap, int r)
{
  r = cha(va_arg(ap, int), r - 1);
  return (r);
}

int	f_di(va_list ap, int r)
{
  r = di(va_arg(ap, int), r - 1);
  return (r);
}

int	f_u(va_list ap, int r)
{
  r = u(va_arg(ap, unsigned int), r - 1);
  return (r);
}
