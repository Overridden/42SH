/*
** my_strcat.c for my_strcat in /home/dovan_n//afs/j7local
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Tue Oct  9 09:29:27 2012 noel dovan
** Last update Thu May 23 10:26:18 2013 noel dovan
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    ++i;
  while (src[j] != '\0')
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
