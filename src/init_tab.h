/*
** init_tab.h for init_tab in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Apr  5 14:10:12 2013 noel dovan
** Last update Wed May 15 20:28:15 2013 noel dovan
*/

#ifndef INIT_TAB_H_
# define INIT_TAB_H_

# include	<stdlib.h>
# include	"my.h"

# define	INHIBITOR_D	'"'
# define	ERR_UNMATCHED	"Unmatched \".\n"

void	my_free_tab(char **tab);
char	**fill_tab(char **tab, char *line, char sep, int inhib);
char	**init_malloc(int size, int nb);
int	inhib_unmatched(char *line);
char	**init_tab(char *line, char sep);

#endif /* INIT_TAB_H_ */
