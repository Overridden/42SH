/*
** init_tab.c for init_tab in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 14:09:30 2013 noel dovan
** Last update Wed May 22 10:15:11 2013 noel dovan
*/

#include "init_tab.h"
#include "misc.h"

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}

char	**fill_tab(char **tab, char *line, char sep, int inhib)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (line[i] != '\0')
    {
      if (line[i] == INHIBITOR_D)
	{
	  ++i;
	  ((inhib == 0) ? (inhib = 1) : (inhib = 0));
	}
      if (line[i] == sep && inhib == 0)
	{
	  tab[j++][k] = '\0';
	  ++i;
	  k = 0;
	}
      if (line[i] != INHIBITOR_D)
	tab[j][k++] = line[i++];
    }
  tab[j][k] = '\0';
  return (tab);
}

char	**init_malloc(int size, int nb)
{
  char	**tab;
  int	i;

  if (!(tab = malloc(sizeof(*tab) * (size * nb + nb))))
    return (NULL);
  i = -1;
  while (++i < nb)
    if (!(tab[i] = malloc(sizeof(*tab[i]) * (size + 1))))
      return (NULL);
  tab[nb] = NULL;
  return (tab);
}

int	inhib_unmatched(char *line)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (line[++i] != '\0')
    if (line[i] == INHIBITOR_D)
      ++j;
  if ((j % 2) == 0)
    return (0);
  else
    return (1);
}

char	**init_tab(char *line, char sep)
{
  char	**tab;

  if (inhib_unmatched(line) == 1)
    {
      fprintf(stderr, "%s", ERR_UNMATCHED);
      return (NULL);
    }
  if (!(tab = init_malloc(my_strlen(line), count_car(line, sep))))
    return (NULL);
  tab = fill_tab(tab, line, sep, 0);
  return (tab);
}
