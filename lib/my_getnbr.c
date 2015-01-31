/*
** my_getnbr.c for my_getnbr in /home/dovan_n//afs/j4local
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Mon Oct 29 14:38:51 2012 noel dovan
** Last update Thu May 23 10:30:06 2013 noel dovan
*/

int	neg(char *str, int res, int i)
{
  while (str[i] >= '0' && str[i] <= '9' && i != 0)
    {
      --i;
      if (str[i] == '-')
	return (-res);
    }
  return (res);
}

int	my_getnbr(char *str)
{
  int	res;
  int	i;

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
      if (res < 0)
	return (0);
    }
  --i;
  res = neg(str, res, i);
  return (res);
}
