/*
** my_fct_nbr.c for PSU_my_printf in /home/puilla_e/System_unix/Printf
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Nov  6 10:12:10 2015 edouard puillandre
** Last update Mon Nov 16 23:33:31 2015 edouard puillandre
*/

#include "./include/my.h"
#include "./include/my_printf.h"

int	my_print_int_sgn(int nbr, char *base, int zero_true, t_nbracc *acc)
{
  int	len_base;
  int	nb_print;

  nb_print = 0;
  if (nbr == 0 && acc->sgn >= 0)
    nb_print = nb_print + my_print_nbracc(acc, zero_true);
  if (zero_true == 1 && nbr == 0)
    nb_print = 1 + my_putchar('0');
  len_base = my_strlen(base);
  if (nbr < 0)
    {
      acc->nb = acc->nb - 1;
      zero_true == 1 && acc->sgn == - 1 ? my_putchar('-') : 0;
      nb_print = 2 + my_print_int_sgn(nbr / len_base, base, - 1, acc);
      my_putchar(base[nbr % len_base * - 1]);
    }
  else if (nbr > 0)
    {
      acc->nb = acc->nb - 1;
      nb_print = 1 + my_print_int_sgn(nbr / len_base, base, 0, acc);
      my_putchar(base[nbr % len_base]);
    }
  if (zero_true == 1 && acc->sgn == - 1)
    nb_print = nb_print + my_print_nbracc(acc, (nbr != 0) ? 0 : 1);
  return (nb_print);
}

int	my_print_longlong_sgn(long long nbr,
			      char *base,
			      int zero_true,
			      t_nbracc *acc)
{
  int	len_base;
  int	nb_print;

  nb_print = 0;
  if (nbr == 0 && acc->sgn >= 0)
    nb_print = nb_print + my_print_nbracc(acc, zero_true);
  if (zero_true == 1 && nbr == 0)
    nb_print = 1 + my_putchar('0');
  len_base = my_strlen(base);
  if (nbr < 0)
    {
      acc->nb = acc->nb - 1;
      zero_true == 1 && acc->sgn == - 1 ? my_putchar('-') : 0;
      nb_print = 2 + my_print_longlong_sgn(nbr / len_base, base, - 1, acc);
      my_putchar(base[nbr % len_base * - 1]);
    }
  else if (nbr > 0)
  {
    acc->nb = acc->nb - 1;
    nb_print = 1 + my_print_longlong_sgn(nbr / len_base, base, 0, acc);
    my_putchar(base[nbr % len_base]);
  }
  if (zero_true == 1 && acc->sgn == - 1)
    nb_print = nb_print + my_print_nbracc(acc, (nbr != 0) ? 0 : 1);
  return (nb_print);
}

int	my_print_long_sgn(long nbr,
			  char *base,
			  int zero_true,
			  t_nbracc *acc)
{
  int	len_base;
  int	nb_print;

  nb_print = 0;
  if (nbr == 0 && acc->sgn >= 0)
    nb_print = nb_print + my_print_nbracc(acc, zero_true);
  if (zero_true == 1 && nbr == 0)
    nb_print = 1 + my_putchar('0');
  len_base = my_strlen(base);
  if (nbr < 0)
    {
      acc->nb = acc->nb - 1;
      zero_true == 1 && acc->sgn == - 1 ? my_putchar('-') : 0;
      nb_print = 2 + my_print_long_sgn(nbr / len_base, base, - 1, acc);
      my_putchar(base[nbr % len_base * - 1]);
    }
  else if (nbr > 0)
    {
      acc->nb = acc->nb - 1;
      nb_print = 1 + my_print_long_sgn(nbr / len_base, base, 0, acc);
      my_putchar(base[nbr % len_base]);
    }
  if (zero_true == 1 && acc->sgn == - 1)
    nb_print = nb_print + my_print_nbracc(acc, (nbr != 0) ? 0 : 1);
  return (nb_print);
}
