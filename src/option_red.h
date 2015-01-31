/*
** option_red.h for option_red in /home/dovan_n//svn/42sh-2017-nguye_1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Mon Apr 29 13:24:15 2013 noel dovan
** Last update Mon Apr 29 13:30:02 2013 noel dovan
*/

#ifndef OPTION_RED_H_
# define OPTION_RED_H_

# include	<stdlib.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	"my.h"
# include	"string.h"

/* option_red_leftl.c */
int	option_red_leftl_filspere(char *buf, t_all *all, int *pipefd);
int	option_red_leftl_write(char *buff, char *buff2, char *buff2b,
				int *pipefd);
int	option_red_leftl_filsfils(char *buf, int *pipefd);
int	option_red_leftl_fils(char *buf, t_all *all, int *pipefd);
t_all	*option_red_leftl(char *buf, t_all *all, char **check);

/* option_red_rightr.c */
int	option_red_rightr_write(char *buf, int fd, int r);
int	option_red_rightr_filspere(char *buff, int *pipefd);
int	option_red_rightr_filsfils(char *buf, t_all *all, int *pipefd);
int	option_red_rightr_fils(char *buf, t_all *all, int *pipefd);
t_all	*option_red_rightr(char *buf, t_all *all, char **check);

/* option_red_left.c */
int	option_red_left_filspere(char *buff, t_all *all, int *pipefd);
int	option_red_left_write(char *buff, int *pipefd, int r, int fd);
int	option_red_left_filsfils(char *buf, int *pipefd);
int	option_red_left_fils(char *buf, t_all *all, int *pipefd);
t_all	*option_red_left(char *buf, t_all *all, char **check);

/* option_red_right.c */
int	option_red_right_write(char *buf, int fd, int r);
int	option_red_right_filspere(char *buff, int *pipefd);
int	option_red_right_filsfils(char *buf, t_all *all, int *pipefd,
					char **check);
int	option_red_right_fils(char *buf, t_all *all, int *pipefd,
				char **check);
t_all	*option_red_right(char *buf, t_all *all, char **check);

#endif /* OPTION_RED_H_ */
