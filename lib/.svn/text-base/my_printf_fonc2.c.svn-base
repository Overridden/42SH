/*
** my_printf_fonc2.c for my_printf_fonc2 in /home/dovan_n//projets/printf
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Nov 15 08:41:48 2012 noel dovan
** Last update Sun Nov 25 13:18:56 2012 noel dovan
*/

#include <stdarg.h>
#include "string.h"

int	f_o(va_list ap, int r)
{
  r = o(va_arg(ap, unsigned int), "01234567", r - 1);
  return (r);
}

int	f_o_b(va_list ap, int r)
{
  r = o(va_arg(ap, unsigned int), "01", r - 1);
  return (r);
}

int	f_s_octal(va_list ap, int r)
{
  r = s_octal(va_arg(ap, char*), r - 1);
  return (r);
}

int	f_x(va_list ap, int r)
{
  r = x(va_arg(ap, unsigned int), "0123456789abcdef", r - 1);
  return (r);
}

int	f_x_cap(va_list ap, int r)
{
  r = x_cap(va_arg(ap, unsigned int), "0123456789ABCDEF", r - 1);
  return (r);
}
