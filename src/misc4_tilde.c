/*
** misc4_tilde.c for misc4_tilde in /home/dovan_n//svn/42sh-2017-nguye_1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri May 24 17:24:05 2013 noel dovan
** Last update Sun May 26 06:16:09 2013 noel dovan
*/

#include "data.h"
#include "misc.h"

int	format_car_tilde_line(char *buf, char *name)
{
  int	i;
  int	j;

  i = -1;
  while (buf[++i] != '\0')
    {
      j = 0;
      if (buf[i] == name[j])
	{
	  while (name[j] != '\0' && buf[i] == name[j])
	    {
	      ++j;
	      ++i;
	      if (buf[i] == '\0' && name[j] != '\0')
		return (-1);
	    }
	  if (name[j] == '\0')
	    {
	      if (buf[i] != ':')
		return (-1);
	      return (i);
	    }
	}
    }
  return (-1);
}

char	*get_the_user(char *buf, int i)
{
  char	*user;
  int	j;

  if (!(user = malloc(sizeof(*user) * (my_strlen(buf) + 1))))
    return (NULL);
  j = 0;
  while (buf[++i] != ' ' && buf[i] != '\0' && buf[i] != '\t')
    user[j++] = buf[i];
  user[j] = '\0';
  return (user);
}

int	format_car_tilde_seek(int fd, char *buff, char *buf, int i)
{
  int	r;
  int	line;
  char	*user;

  if (!(user = get_the_user(buf, i)))
    return (-1);
  while ((r = read(fd, buff, SIZE)) > 0)
    {
      buff[r] = '\0';
      if ((line = format_car_tilde_line(buff, user)) != -1)
  	{
	  free(user);
	  while (buff[line] != '/' && buf[line + 1] != 'h')
	    ++line;
    	  return (line);
	}
    }
  fprintf(stderr, "%s%s.\n", ERR_NOUSER, user);
  free(user);
  return (-1);
}

void	insert_tilde(char *buf, int i, char *buff, int line)
{
  int	j;
  char	*right;
  int	k;

  j = i;
  if (!(right = malloc(sizeof(*right) * (my_strlen(buf) + 1))))
    return ;
  k = 0;
  while (buf[j] != ' ' && buf[j] != '\0' && buf[j] != '\t')
    ++j;
  if (buf[j] != '\0')
    {
      while (buf[j] != '\0')
	right[k++] = buf[j++];
      right[k] = '\0';
    }
  while (buff[line] != ':')
    buf[i++] = buff[line++];
  k = 0;
  while (right[k] != '\0')
    buf[i++] = right[k++];
  buf[i] = '\0';
  free(right);
}

char	*format_car_tilde(char *buf, int i)
{
  int	fd;
  char	*buff;
  int	line;

  if (access("/etc/passwd", F_OK) == -1)
    return (NULL);
  if ((fd = open("/etc/passwd", O_RDONLY)) == -1)
    return (NULL);
  if (!(buff = malloc(sizeof(*buff) * (SIZE + 1))))
    return (NULL);
  if ((line = format_car_tilde_seek(fd, buff, buf, i)) == -1)
    {
      if (close(fd) == -1)
	return (NULL);
      free(buff);
      return (buf);
    }
  if (close(fd) == -1)
    return (NULL);
  insert_tilde(buf, i, buff, line);
  free(buff);
  return (buf);
}
