/*
** my_print_nbracc.c for PSU_2015_my_printf in /home/puilla_e/System_unix/rendu/PSU_2015_my_printf
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Nov 13 18:05:41 2015 edouard puillandre
** Last update Mon Nov 16 23:34:14 2015 edouard puillandre
*/

#include "./include/my_printf.h"
#include "./include/my.h"
#include <unistd.h>

int	my_get_nbracc(t_nbracc *acc, char **str)
{
  int	i;

  i = 0;
  acc->nb = 0;
  while (**str >= '0' && **str <= '9')
    {
      acc->nb = **str - 48 + acc->nb * 10;
      *str = *str + 1;
      i = i + 1;
    }
  return (i);
}
int	my_fill_nbacc(t_nbracc *acc, char **str)
{
  int	i;

  if (*str[0] == 32)
    {
      *str = *str + 1;
      my_fill_nbacc(acc, str);
    }
  if (*str[0] == '-')
    acc->sgn = - 1;
  else if (*str[0] == '+')
    acc->sgn = 1;
  else
    acc->sgn = 0;
  *str = (acc->sgn == 0) ? *str : *str + 1;
  i = (acc->sgn == 0) ? 0 : 1;
  acc->zero = (**str == '0') ? 1 : 0;
  acc->nb = 0;
  acc->len = my_get_nbracc(acc, str) + i;
  return (0);
}

int	my_putstr_error(char *str)
{
  while (*str != '\0')
    {
      write(2, str, 1);
      str = str + 1;
    }
  return (0);
}

int	my_print_characc(t_nbracc *acc, int len)
{
  int	nb_print;

  nb_print = 0;
  while (acc->nb > len)
    {
      acc->nb = acc->nb - 1;
      my_putchar(32);
      nb_print = nb_print + 1;
    }
  return (nb_print);
}

int	my_print_nbracc(t_nbracc *acc, int zero_true)
{
  int	nb_print;

  nb_print = 0;
  if (zero_true == 1 || zero_true == - 1)
    acc->nb = acc->nb - 1;
  if (acc->sgn == 1 && acc->zero == 1 && zero_true != - 1)
    nb_print = 1 + my_putchar('+');
  if (zero_true == - 1 && acc->zero == 1)
    nb_print = 1 + my_putchar('-');
  while (acc->nb > 0)
    {
      if (acc->zero == 1 && acc->sgn >= 0)
	my_putchar('0');
      else
	my_putchar(32);
      nb_print = nb_print + 1;
      acc->nb = acc->nb - 1;
    }
  if (zero_true == - 1 && acc->zero == 0)
    nb_print = 1 + my_putchar('-');
  if (acc->sgn == 1 && acc->zero == 0)
    nb_print = 1 + my_putchar('+');
  return (nb_print);
}
