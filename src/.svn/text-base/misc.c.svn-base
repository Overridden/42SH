/*
** misc.c for misc in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Apr  4 21:54:03 2013 noel dovan
** Last update Thu May 23 18:23:31 2013 noel dovan
*/

#include "misc.h"
#include "init_tab.h"

int	check_correct_red(char *buf)
{
  int	i;

  i = -1;
  if (buf[0] == '\0')
    {
      free(buf);
      fprintf(stderr, "%s", ERR_SYNTAX);
      return (1);
    }
  while (buf[++i] != '\0')
    {
      if (buf[i] == '<' || buf[i] == '>')
	{
	  free(buf);
	  fprintf(stderr, "%s", ERR_SYNTAX);
	  return (1);
	}
    }
  return (0);
}

int	count_car(char *line, char car)
{
  int	i;
  int	j;
  int	inhib;

  i = -1;
  j = 0;
  inhib = 0;
  while (line[++i] != '\0')
    {
      if (line[i] == INHIBITOR_D)
        {
	  ++i;
	  ((inhib == 0) ? (inhib = 1) : (inhib = 0));
        }
      if (line[i] == car && inhib == 0)
	++j;
    }
  ++j;
  return (j);
}

void	clean_str(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    str[i] = '\0';
}

void	epur_begin_end(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] == ' ')
    ;
  while (str[i] != '\0')
    str[j++] = str[i++];
  if (i > 0)
    --i;
  while (str[i] == ' ')
    {
      --i;
      --j;
    }
  while (str[i] != '\0')
    {
      str[j++] = '\0';
      ++i;
    }
  str[i] = '\0';
}

void	epur_str(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != '\0')
    if (str[i] == '\t')
      str[i] = ' ';
  i = -1;
  while (str[++i] == ' ')
    ;
  while (str[i] != '\0')
    {
      while ((str[i] == ' ' && str[i - 1] == ' '))
	++i;
      str[j++] = str[i++];
    }
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  --j;
  while (j < i)
    str[j++] = '\0';
}
