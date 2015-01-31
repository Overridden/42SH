/*
** create_check.c for create_check in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Thu Apr  4 23:24:15 2013 noel dovan
** Last update Tue May 14 19:52:06 2013 noel dovan
*/

#include "data.h"
#include "create.h"

void	my_free_check(char **check)
{
  free(check[0]);
  free(check[1]);
  free(check[2]);
  free(check[3]);
  free(check[4]);
  free(check[5]);
  free(check[6]);
  free(check[7]);
  free(check[8]);
  free(check[9]);
  free(check[10]);
  free(check[11]);
  free(check[12]);
  free(check[13]);
  free(check);
}

int	check_if_null(char **check)
{
  int	i;

  i = -1;
  while (check[++i])
    ;
  if (i != 14)
    return (1);
  return (0);
}

char	**create_check(char **check)
{
  if (!(check = malloc(sizeof(*check) * 15 * 9)))
    return (NULL);
  check[0] = my_strdup(S_SC);
  check[1] = my_strdup(S_AND);
  check[2] = my_strdup(S_OR);
  check[3] = my_strdup(S_PIPE);
  check[4] = my_strdup("<<");
  check[5] = my_strdup("<");
  check[6] = my_strdup(">");
  check[7] = my_strdup(">>");
  check[8] = my_strdup("exit");
  check[9] = my_strdup("echo");
  check[10] = my_strdup("cd");
  check[11] = my_strdup("unsetenv");
  check[12] = my_strdup("setenv");
  check[13] = my_strdup("env");
  check[14] = NULL;
  if (check_if_null(check) == 1)
    return (NULL);
  return (check);
}
