/*
** init_tab.c for PSU_2015_my_printf in /home/puilla_e/System_unix/rendu/PSU_2015_my_printf
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Tue Nov 10 15:52:07 2015 edouard puillandre
** Last update Mon Nov 16 23:33:10 2015 edouard puillandre
*/

#include "./include/my_printf.h"
#include <stdlib.h>
#include "./include/my.h"

int	my_fill_flag_size(t_flag *tab)
{
  tab[11].str = "hh";
  tab[11].fct = &(my_trad_int_sgn);
  tab[11].opt = &(my_trad_int_uns);
  tab[11].base = BASE_NULL;
  tab[12].str = "ll";
  tab[12].fct = &(my_trad_longlong_sgn);
  tab[12].opt = &(my_trad_longlong_uns);
  tab[12].base = BASE_NULL;
  tab[13].str = "h";
  tab[13].fct = &(my_trad_int_sgn);
  tab[13].opt = &(my_trad_int_uns);
  tab[13].base = BASE_NULL;
  tab[14].str = "l";
  tab[14].fct = &(my_trad_long_sgn);
  tab[14].opt = &(my_trad_long_uns);
  tab[14].base = BASE_NULL;
  return (0);
}

int	my_fill_char(t_flag *tab)
{
  tab[0].str = "p";
  tab[0].fct = &(my_print_ptr);
  tab[0].base = BASE_X_MIN;
  tab[8].str = "c";
  tab[8].fct = &(my_print_char);
  tab[8].base = BASE_NULL;
  tab[9].str = "s";
  tab[9].fct = &(my_print_str);
  tab[9].base = BASE_NULL;
  tab[10].str = "S";
  tab[10].fct = &(my_print_str_maj);
  tab[10].base = BASE_O;
  return (0);
}

int	my_fill_int(t_flag *tab)
{
  int	i;

  i = 3;
  while (i <= 7)
    {
      tab[i].fct = &(my_trad_int_uns);
      i = i + 1;
    }
  tab[1].str = "d";
  tab[1].base = BASE_D;
  tab[1].fct = &(my_trad_int_sgn);
  tab[2].str = "i";
  tab[2].base = BASE_D;
  tab[2].fct = &(my_trad_int_sgn);
  tab[3].str = "u";
  tab[3].base = BASE_D;
  tab[4].str = "b";
  tab[4].base = BASE_B;
  tab[5].str = "o";
  tab[5].base = BASE_O;
  tab[6].str = "x";
  tab[6].base = BASE_X_MIN;
  tab[7].str = "X";
  tab[7].base = BASE_X_MAJ;
  return (0);
}

t_flag		*my_init_tab(void)
{
  t_flag	*tab;

  tab = malloc(sizeof(t_flag) * NBR_FLAG);
  if (tab == NULL)
    {
      my_putstr_error(ERROR_MSG);
      return (tab);
    }
  my_fill_int(tab);
  my_fill_char(tab);
  my_fill_flag_size(tab);
  return (tab);
}
