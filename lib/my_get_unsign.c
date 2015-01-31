/*
** my_get_unsign.c for my_get_unsign in /u/all/dovan_n/rendu/lib/my
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sat Nov 10 22:49:14 2012 noel dovan
** Last update Thu May 23 10:29:43 2013 noel dovan
*/

unsigned int	my_get_unsign(char *str)
{
  unsigned int	res;
  int		i;

  i = 0;
  res = 0;
  if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-'))
    return (0);
  while (str[i] == '-' || str[i] == '+')
    ++i;
  while (str[i] >= '0' && str[i] <= '9')
    {
      res = (str[i] - 48) + res;
      if (str[i + 1] >= '0' && str[i + 1] <= '9')
        res = res * 10;
      ++i;
    }
  return (res);
}
