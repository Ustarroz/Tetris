/*
** fct_opt2.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 16:51:51 2016 edouard puillandre
** Last update Sat Mar 19 15:41:37 2016 edouard puillandre
*/

#include "tetris.h"

int	get_cpl_nbr(char *str, bool first)
{
  int	i;
  int	nb;
  bool	end;
  bool	check;

  i = - 1;
  nb = 0;
  end = true;
  check = first;
  while (str[++i] != '\0' && end)
    if (check && str[i] >= '0' && str[i] <= '9')
      nb = 10 * nb + str[i] - '0';
    else if (first && str[i] == ',')
      end = false;
    else if (check && (str[i] < '0' || str[i] > '9'))
      return (- 1);
    else if (str[i] == ',')
      check = true;
  if (nb <= 0 || i > my_strlen(INT_MAX))
    return (- 1);
  return (nb);
}

int	set_map(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("map eq\n");
#endif
  *i = *i + 1;
  if (*i + 1 >= argc || check_int(argv[*i]) != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  tetris->map->width = my_getnbr(argv[*i]);
  *i = *i + 1;
  if (tetris->map->width == 0 || check_int(argv[*i]) != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 2, true);
      return (- 1);
    }
  if ((tetris->map->height = my_getnbr(argv[*i])) == 0)
   {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 2, true);
      return (- 1);
    }
  return (0);
}

int	set_map_eq(t_tetris *tetris, int *i, char **argv)
{
  int	len;

#ifdef DEBUG
  my_printf("map eq\n");
#endif
  len = my_strlen("--map-size=");
  tetris->map->height = get_cpl_nbr(argv[*i] + len, true);
  tetris->map->width = get_cpl_nbr(argv[*i] + len, false);
  if (tetris->map->width == - 1 || tetris->map->height == - 1)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i, true);
      return (- 1);
    }
  return (0);
}

int	set_w_eq(t_tetris *tetris, int *i, char **argv)
{
#ifdef DEBUG
  my_printf("without eq\n");
#endif
  if (my_strcmp(argv[*i], "--without-next") != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i, true);
      return (- 1);
    }
  tetris->next->valid = false;
  return (0);
}

int	set_w(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("without\n");
#endif
  (void) argc;
  (void) argv;
  (void) *i;
  tetris->next->valid = false;
  return (0);
}
