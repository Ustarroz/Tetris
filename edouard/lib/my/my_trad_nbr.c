/*
** my_trad_nbr.c for PSU_my_printf in /home/puilla_e/System_unix/Printf
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Nov  6 10:12:10 2015 edouard puillandre
** Last update Mon Nov 16 23:34:55 2015 edouard puillandre
*/

#include "./include/my.h"
#include "./include/my_printf.h"

int    	my_trad_int_sgn(va_list ap,
			char *base,
			t_nbracc *acc)
{
  int	nbr;

  nbr = va_arg(ap, int);
  return (my_print_int_sgn(nbr, base, 1, acc));
}

int	       	my_trad_longlong_sgn(va_list ap,
				     char *base,
				     t_nbracc *acc)
{
  long long	nbr;

  nbr = va_arg(ap, long long);
  return (my_print_longlong_sgn(nbr, base, 1, acc));
}

int    	my_trad_long_sgn(va_list ap,
			 char *base,
			 t_nbracc *acc)
{
  long	nbr;

  nbr = va_arg(ap, long);
  return (my_print_long_sgn(nbr, base, 1, acc));
}
