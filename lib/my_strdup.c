/*
** my_strdup.c for my_strdup in /u/all/dovan_n/rendu/lib/my
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Nov  1 20:21:18 2012 noel dovan
** Last update Thu Apr 11 00:00:12 2013 noel dovan
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  if (src == NULL)
    return (NULL);
  i = my_strlen(src);
  if (!(dest = malloc(sizeof(*dest) * (i + 1 + 2))))
    return (NULL);
  i = -1;
  while (src[++i] != '\0')
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
