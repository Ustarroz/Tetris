/*
** my_printf.c for PSU_2015_my_printf in /home/puilla_e/System_unix/rendu/PSU_2015_my_printf
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Nov  4 16:23:59 2015 edouard puillandre
** Last update Sun Jan 24 19:03:41 2016 edouard puillandre
*/

#include "./include/my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "./include/my_printf.h"

int	my_print_space(char **str, int	j, t_flag *tab, va_list ap)
{
  int	space_true;
  int	i;
  int	nb_prnt;

  i = 1;
  space_true = nb_prnt = 0;
  while (*(*str - i) != '%')
    {
      if (*(*str - i) == 32)
	space_true = 1;
      i = i + 1;
    }
  if (**str != '\0' && j == NBR_FLAG)
    nb_prnt = nb_prnt + my_putchar('%') + 1;
  if (space_true == 1 && **str != '\0' && (j <= FLAG_SPACE || j == NBR_FLAG))
    nb_prnt = nb_prnt + my_putchar(32) + 1;
  if (j < FLAG_SIZE && j >= 0)
    nb_prnt = nb_prnt + tab[j].fct(ap, tab[j].base, tab[j].acc);
  i = tab->acc->nb;
  tab->acc->zero = (tab->acc->zero == 0 && tab->acc->nb == 0) ? 0 : 1;
  tab->acc->nb = tab->acc->len;
  if (**str != '%' && j == NBR_FLAG)
    nb_prnt = nb_prnt + my_print_int_sgn(i, BASE_D, tab->acc->zero, tab->acc);
  *str = (**str != '%' && j == NBR_FLAG) ? *str - 1 : *str;
  return ((**str == '\0') ? - 1 : nb_prnt);
}

int	my_str_in_str(char *dest, char *to_find)
{
  int	i;

  i = 0;
  while (dest[i] != '\0' && to_find[i] != '\0')
    {
      if (dest[i] != to_find[i])
	return (0);
      i = i + 1;
    }
  if (to_find[i] != '\0')
    return (0);
  return (1);
}

int	my_print_flag_size(char **str, t_flag *tab, va_list ap, int i)
{
  int	j;
  int	nb_print;

  j = 0;
  nb_print = 0;
  *str = *str + my_strlen(tab[i].str);
  while (j < FLAG_SIZE)
    {
      if (my_str_in_str(*str, tab[j].str))
	{
	  if (j <= FLAG_SPACE)
	    nb_print = nb_print + my_print_space(str, - 1, tab, ap);
	  if (j == 1 || j == 2)
	    nb_print = nb_print + tab[i].fct(ap, tab[j].base, tab[i].acc);
	  else if (j > 2 && j <= 7)
	    nb_print = nb_print + tab[i].opt(ap, tab[j].base, tab[i].acc);
	  else
	    nb_print = nb_print + tab[j].fct(ap, tab[j].base, tab[i].acc);
	  return (nb_print);
	}
      j = j + 1;
    }
  nb_print = nb_print + my_print_space(str, NBR_FLAG, tab, ap);
  return (nb_print);
}

int		my_check_flag(char **str, t_flag *tab, va_list ap)
{
  int		i;
  int		tab_true;
  t_nbracc	acc;

  i = 0;
  tab_true = 0;
  *str = *str + 1;
  my_fill_nbacc(&acc, str);
  tab[0].acc = &acc;
  while (i < NBR_FLAG && tab_true == 0)
    {
      if (my_str_in_str(*str, tab[i].str) == 1)
	tab_true = 1;
      else
	i = i + 1;
    }
  if (i != NBR_FLAG)
    tab[i].acc = &acc;
  if (i >= FLAG_SIZE && i != NBR_FLAG)
    return (my_print_flag_size(str, tab, ap, i));
  else
    return (my_print_space(str, i, tab, ap));
  return (0);
}

int		my_printf(char *str, ...)
{
  va_list	ap;
  t_flag	*tab;
  int		nb_print;

  nb_print = 0;
  if ((tab = my_init_tab()) == NULL)
    return (- 2);
  va_start(ap, str);
  while (*str != '\0')
    {
      if (*str == '%')
	nb_print = nb_print + my_check_flag(&str, tab, ap);
      else
	{
	  my_putchar(*str);
	  nb_print = nb_print + 1;
	}
      str = str + 1;
    }
  va_end(ap);
  free(tab);
  return (nb_print);
}
