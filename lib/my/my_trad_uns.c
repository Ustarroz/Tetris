/*
** my_trad_uns.c for PSU_my_printf in /home/puilla_e/System_unix/Printf
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Nov  6 10:12:10 2015 edouard puillandre
** Last update Mon Nov 16 23:35:07 2015 edouard puillandre
*/

#include "./include/my.h"
#include "./include/my_printf.h"

int		my_trad_int_uns(va_list ap,
				char *base,
				t_nbracc *acc)
{
  unsigned int	nbr;

  nbr = va_arg(ap, unsigned int);
  return (my_print_int_uns(nbr, base, 1, acc));
}

int			my_trad_longlong_uns(va_list ap,
					     char *base,
					     t_nbracc *acc)
{
  unsigned long long	nbr;

  nbr = va_arg(ap, unsigned long long);
  return (my_print_longlong_uns(nbr, base, 1, acc));
}

int	       	my_trad_long_uns(va_list ap,
				 char *base,
				 t_nbracc *acc)
{
  unsigned long	nbr;

  nbr = va_arg(ap, unsigned long);
  return (my_print_long_uns(nbr, base, 1, acc));
}
