/*
** my_printf.c for my_printf in /home/dovan_n//printf
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Wed Nov  7 20:52:01 2012 noel dovan
** Last update Thu May 23 10:29:30 2013 noel dovan
*/

#include <stdarg.h>
#include <stdlib.h>
#include "string.h"

int		dec_to_count(unsigned int nb2, unsigned int rest2,
			     int baseto, int l)
{
  while (nb2 > 0)
    {
      rest2 = nb2 % baseto;
      nb2 = nb2 / baseto;
      l = l + 1;
    }
  rest2 = rest2;
  return (l);
}

int		dec_to_less(unsigned int nb, int baseto,
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
  my_putstr(res);
  free(res);
  return (r);
}

int		flags(const char *format, int i, va_list ap, int r)
{
  char	flag[14] ="%scdiuobSxXpm";
  int	(*fonc[14])(va_list, int);
  int	j;

  j = 0;
  fonc[0] = &f_percent;
  fonc[1] = &f_s;
  fonc[2] = &f_cha;
  fonc[3] = &f_di;
  fonc[4] = &f_di;
  fonc[5] = &f_u;
  fonc[6] = &f_o;
  fonc[7] = &f_o_b;
  fonc[8] = &f_s_octal;
  fonc[9] = &f_x;
  fonc[10] = &f_x_cap;
  fonc[11] = &f_p;
  fonc[12] = &f_m;
  while (format[i + 1] != flag[j])
    {
      if (flag[j] == '\0')
	return (r + my_putchar('%') - 1);
      ++j;
    }
  return ((*fonc[j])(ap, r));
}

int		fake(const char *format, int i)
{
  char		flag[14] ="%scdiuobSxXpm";
  int	j;

  j = 0;
  while (j != 13)
    {
      if (format[i + 1] == flag[j])
	return (i);
      ++j;
    }
  return (i - 1);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;
  int		r;

  i = 0;
  r = 0;
  va_start(ap, format);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  r = flags(format, i, ap, r);
	  i = fake(format, i);
	  ++i;
	  ++r;
	}
      else
	  my_putchar(format[i]);
      ++i;
      ++r;
    }
  va_end(ap);
  return (r);
}
