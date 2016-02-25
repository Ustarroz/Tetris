/*
** my_fct_char.c for PSU_2015_my_printf in /home/puilla_e/System_unix/rendu/PSU_2015_my_printf
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Tue Nov 10 15:01:08 2015 edouard puillandre
** Last update Mon Nov 16 23:32:59 2015 edouard puillandre
*/

#include <stdarg.h>
#include "./include/my_printf.h"
#include "./include/my.h"
#include <stdlib.h>
#include <stdio.h>

int	my_put_str_oct(char *str, char *base)
{
  int	len_base;
  int	i;
  int	nb;

  i = 0;
  len_base = my_strlen(base);
  while (str[i] != '\0')
    {
      if (str[i] < 0)
	nb = str[i] + 2 * 128;
      else
	nb = str[i];
      if (str[i] < 32 || str[i] == 127)
	{
	  my_putchar(92);
	  my_putchar(base[nb / len_base / len_base % len_base]);
	  my_putchar(base[nb / len_base % len_base]);
	  my_putchar(base[nb % len_base]);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_print_str_maj(va_list ap, char *base, t_nbracc *acc)
{
  int	i;
  char	*str;
  int	nb_print;

  str = va_arg(ap, char *);
  nb_print = 0;
  i = 0;
  if (str == NULL)
    return (- 2);
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	nb_print = nb_print + 4;
      else
	nb_print = nb_print + 1;
      i = i + 1;
    }
  if (acc->sgn >= 0)
    nb_print = nb_print + my_print_characc(acc, nb_print);
  my_put_str_oct(str, base);
  if (acc->sgn == - 1)
    nb_print = nb_print + my_print_characc(acc, nb_print);
  return (nb_print);
}

int	my_print_char(va_list ap, char *base, t_nbracc *acc)
{
  char	c;
  int	nb_print;

  nb_print = base[0] + 1;
  if (acc->sgn >= 0)
    nb_print = nb_print + my_print_characc(acc, nb_print);
  c = va_arg(ap, int);
  my_putchar(c);
  if (acc->sgn == - 1)
    nb_print = nb_print + my_print_characc(acc, nb_print);
  return (nb_print);
}

int	my_print_str(va_list ap, char *base, t_nbracc *acc)
{
  int	i;
  char	*str;
  int	nb_print;

  str = va_arg(ap, char *);
  if (str == NULL)
    return (- 2);
  i = 0;
  if (acc->sgn >= 0)
    nb_print = i + my_print_characc(acc, my_strlen(str));
  while (str[i] != *base)
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  if (acc->sgn >= 0)
    nb_print = i + my_print_characc(acc, my_strlen(str));
  return (nb_print);
}

int		my_print_ptr(va_list ap, char *base, t_nbracc *acc)
{
  unsigned long nbr;
  void		*ptr;
  int		nb_print;

  ptr = va_arg(ap, void *);
  nbr = (unsigned long) ptr;
  nb_print = my_print_long_ptr(nbr, base, 1, acc);
  return (nb_print);
}
