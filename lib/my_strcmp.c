/*
** my_strcmp.c for my_strcmp in /home/dovan_n//afs
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Wed Oct 10 17:44:20 2012 noel dovan
** Last update Thu May 23 10:26:13 2013 noel dovan
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	r;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      r = s1[i] - s2[i];
      if (r != 0)
	return (r);
      ++i;
    }
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else if (s1[i] == '\0')
    return (1);
  else
    return (-1);
}
