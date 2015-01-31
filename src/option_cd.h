/*
** option_cd.h for option_cd in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Apr  7 22:07:33 2013 noel dovan
** Last update Mon May 13 18:22:29 2013 noel dovan
*/

#ifndef OPTION_CD_H_
# define OPTION_CD_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	"string.h"

# define	ERR_CD_WRONG	"Command not found.\n"
# define	ERR_CD_NO	"No such file or directory.\n"
# define	ERR_CD_PERM	"Permission denied.\n"
# define	ERR_CD_FILE	"Not a directory.\n"
# define	ERR_CD_ARG	"cd: Too many arguments.\n"
# define	ERR_CD_HYPHEN	"cd: Do a cd command first.\n"
# define	ERR_CD_HOME	"cd: HOME unseted.\n"

/* option_cd.c */
t_all	*option_cd_buf(char *buf, t_all *all, char **check);
t_all	*option_cd_hyphen(t_all *all, char **check);
t_all	*option_cd_back(t_all *all, char **check);
t_all	*option_cd_home(t_all *all, char **check);
t_all	*option_cd(char *buf, t_all *all, char **check);

/* option_cd2.c */
void	option_cd_error(char *cd);
t_all	*option_cd_exec(char *cd, t_all *all, char **check);

#endif /* OPTION_CD_H_ */
