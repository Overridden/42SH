/*
** string.h for string in /home/dovan_n//projets/printf
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Wed Nov 14 19:00:00 2012 noel dovan
** Last update Sun Apr 28 11:00:51 2013 noel dovan
*/

#ifndef STRING_H_
# define STRING_H_

# include	<stdarg.h>
# include	"my.h"

# define	FI	format[i + 1]

/* my_printf.c */
int	dec_to_count(unsigned int nb2, unsigned int rest2,
		     int baseto, int l);
int	dec_to_less(unsigned int nb, int baseto,
		    unsigned int nb2, int r);
int	flags(const char *format, int i, va_list ap, int r);
int	fake(const char *format, int i);
int	my_printf(const char *format, ...);

/* my_printf_flag.c */
int	s(char *str, int r);
int	cha(char c, int r);
int	di(int nb, int r);
int	u(unsigned int unb, int r);
int	o(unsigned int nb, char *base_to, int r);

/* my_printf_flag2.c */
int	my_put_octal(char *str);
int	dec_to_octal(unsigned int nb, int baseto,
		     unsigned int nb2, int r);
int	s_octal(char *str, int r);
int	my_nbrlen(int nb, int r);
int	my_unsignlen(unsigned int nb, int r);

/* my_printf_flag3.c */
int	my_put_hex(char *str);
int	dec_to_hex(unsigned int nb, int baseto,
		   unsigned int nb2, int r);
int	x(unsigned int nb, char *base_to, int r);

/* my_printf_flag4.c */
void	my_putstr_hex(char *str);
int	my_put_hex_cap(char *str);
int	dec_to_hex_cap(unsigned int nb, int baseto,
		       unsigned int nb2, int r);
int	x_cap(unsigned int nb, char *base_to, int r);

/* my_printf_flag5.c */
int	p2(int nb, int baseto, int nb2, int r);
int	p(int nb, char *base_to, int r);
int	f_p(va_list ap, int r);
int	f_m(va_list ap, int r);

/* my_printf_fonc.c */
int	f_percent(va_list ap, int r);
int	f_s(va_list ap, int r);
int	f_cha(va_list ap, int r);
int	f_di(va_list ap, int r);
int	f_u(va_list ap, int r);

/* my_printf_fonc2.c */
int	f_o(va_list ap, int r);
int	f_o_b(va_list ap, int r);
int	f_s_octal(va_list ap, int r);
int	f_x(va_list ap, int r);
int	f_x_cap(va_list ap, int r);

#endif /* STRING_H_ */
