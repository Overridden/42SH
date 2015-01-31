/*
** my_nbrlen.c for my_nbrlen in /u/all/dovan_n/rendu/lib/my
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Nov 25 13:21:26 2012 noel dovan
** Last update Sun Nov 25 13:21:38 2012 noel dovan
*/

int	my_nbrlen(int nb, int r)
{
  if (nb < 0)
    my_nbrlen(nb * -1, r + 1);
  else if (nb >= 10)
    my_nbrlen(nb / 10, r + 1);
  else
    return (r + 1);
}
