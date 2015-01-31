/*
** my.h for my in /home/dovan_n//afs/j9local
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Mon Oct 22 12:08:47 2012 noel dovan
** Last update Fri May 24 13:25:14 2013 noel dovan
*/

#ifndef MY_H_
# define MY_H_

int	my_putchar(char c);
void	my_put_nbr(int nb);
void	my_putnbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_strcpy(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
void	my_putnbr_base(int nb, char *base_to);
char	*my_strcat(char *dest, char *src);
char	*my_strdup(char *src);
char	*convert_base(char *nbr, char *base_from, char *base_to);
unsigned int	my_get_unsign(char *str);
int	my_put_unsign(unsigned int nb);
int	my_nbrlen(int nb, int r);
int	my_unsignlen(unsigned int nb, int r);
int	dec_to_base_count(int nb, int baseto);
char	*dec_to_base(int nb, int baseto, char *base_to);
int	base_to_dec(int nb, char *nbr, int basefrom);
int	my_power_it(int nb, int power);

#endif /* MY_H_ */
