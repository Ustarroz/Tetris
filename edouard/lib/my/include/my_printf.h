/*
** my_printf.h for PSU_2015_my_printf in /home/puilla_e/System_unix/rendu/PSU_2015_my_printf/include
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Tue Nov 10 12:03:53 2015 edouard puillandre
** Last update Sun Jan 24 19:08:23 2016 edouard puillandre
*/

#include <stdarg.h>

#ifndef		MY_PRINTF_H_
# define	MY_PRINT_H_

typedef struct	s_nbracc
{
  int		sgn;
  int		nb;
  int		zero;
  int		len;
}		t_nbracc;

typedef	struct	s_flag
{
  char		*str;
  int		(*fct)(va_list, char *, t_nbracc *);
  int		(*opt)(va_list, char *, t_nbracc *);
  char		*base;
  t_nbracc	*acc;
}		t_flag;

# define	BASE_NULL "\0"
# define	BASE_B "01"
# define	BASE_O "01234567"
# define	BASE_D "0123456789"
# define	BASE_X_MIN "0123456789abcdef"
# define	BASE_X_MAJ "0123456789ABCDEF"
# define	NBR_FLAG 15
# define	FLAG_SPACE 2
# define	FLAG_SIZE 11
# define	ERROR_MSG "Error"

int	my_printf(char *, ...);
int	my_print_int_sgn(int, char *, int, t_nbracc *);
int	my_print_long_sgn(long, char *, int, t_nbracc *);
int	my_print_longlong_sgn(long long, char *, int, t_nbracc *);
int	my_print_int_uns(unsigned int, char *, int, t_nbracc *);
int	my_print_long_uns(unsigned long, char *, int, t_nbracc *);
int	my_print_long_ptr(unsigned long, char *, int, t_nbracc *);
int	my_print_longlong_uns(unsigned long long, char *, int, t_nbracc *);
int	my_print_ptr(va_list, char *, t_nbracc *);
int	my_print_str_maj(va_list, char *, t_nbracc *);
int	my_print_char(va_list, char *, t_nbracc *);
int	my_print_str(va_list, char *, t_nbracc *);
int	my_trad_int_sgn(va_list, char *, t_nbracc *);
int	my_trad_long_sgn(va_list, char *, t_nbracc *);
int	my_trad_longlong_sgn(va_list, char *, t_nbracc *);
int	my_trad_int_uns(va_list, char *, t_nbracc *);
int	my_trad_long_uns(va_list, char *, t_nbracc *);
int	my_trad_longlong_uns(va_list, char *, t_nbracc *);
t_flag	*my_init_tab(void);
int	my_fill_nbacc(t_nbracc *, char **);
int	my_putstr_error(char *);
int	my_print_characc(t_nbracc *, int);
int	my_print_nbracc(t_nbracc *, int);

#endif	/* MY_PRINT_H_ */
