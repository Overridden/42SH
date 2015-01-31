/*
** misc5.c for misc5 in /home/dovan_n//svn/42sh-2017-nguye_1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Tue May 14 18:00:59 2013 noel dovan
** Last update Wed May 22 10:14:29 2013 noel dovan
*/

#include "data.h"
#include "misc.h"

void	epur_for_left_red(char *buf)
{
  int	i;

  i = -1;
  while (buf[++i] != '<' && buf[i] != '|' && buf[i] != '>' && buf[i] != '\0')
    ;
  if (buf[i - 1] == ' ')
    buf[i - 1] = '\0';
  else
    buf[i] = '\0';
}

int	check_if_begin(char *buf, char *red, int i)
{
  int	j;

  j = -1;
  while (red[++j] != '\0')
    if (buf[i] == red[j])
      ++i;
  if (i != j)
    return (-1);
  if (buf[i] == ' ')
    ++i;
  while (buf[i] != ' ')
    ++i;
  return (i);
}

void	check_red_begin(char *buf, char *red)
{
  char	*buff;
  int	i;
  int	j;
  int	k;

  i = 0;
  if ((i = check_if_begin(buf, red, i)) == -1)
    return;
  if (!(buff = malloc(sizeof(*buff) * (my_strlen(buf) + 1))))
    return;
  j = -1;
  while (++j < i)
    buff[j] = buf[j];
  buff[j] = '\0';
  k = 0;
  while (buf[++i] != '\0')
    buf[k++] = buf[i];
  j = -1;
  while (buff[++j] != '\0')
    buf[k++] = buff[j];
  buf[k] = '\0';
  free(buff);
}
