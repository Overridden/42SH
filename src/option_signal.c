/*
** option_signal.c for option_signal in /home/dovan_n//svn/biji-repo1/src
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Sun Apr  7 21:08:45 2013 noel dovan
** Last update Fri May 24 13:26:05 2013 noel dovan
*/

#include "option_signal.h"

void	option_signal(int signal)
{
  if (signal == SIGSEGV)
    fprintf(stderr, "Sig %d: %s\n", signal, ERR_SEG);
  else if (signal == SIGFPE)
    fprintf(stderr, "Sig %d: %s\n", signal, ERR_FLO);
  else
    {
      if (signal != 0 && signal <= 31)
	fprintf(stderr, "Sig %d\n", signal);
    }
}
