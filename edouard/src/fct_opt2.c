/*
** fct_opt2.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 16:51:51 2016 edouard puillandre
** Last update Mon Mar  7 17:52:11 2016 edouard puillandre
*/

#include "tetris.h"

int	set_lvl(t_tetris *tetris, int *i, char **argv, bool eq_true)
{
  int	len;

  my_printf("lvl\n");
  if (eq_true == false)
    {
      *i = *i + 1;
      if (*i > tetris->nb_opt || check_int(argv[*i]) != 0)
 	{
	  my_putstr_error(ARG_ERR_MSG);
	  my_putnbr_error(*i - 1, true);
	  return (- 1);
	}
      tetris->game->lvl = my_getnbr(argv[*i]);
    }
  else
    {
      len = my_strlen("--level=");
      if (check_int(argv[*i] + len) != 0)
 	{
	  my_putstr_error(ARG_ERR_MSG);
	  my_putnbr_error(*i, true);
	  return (- 1);
	}
      tetris->game->lvl = my_getnbr(argv[*i] + len);
    }
  return (0);
}

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

int	set_map_m(t_tetris *tetris, int *i, char **argv)
{
  *i = *i + 1;
  if (*i + 1 > tetris->nb_opt || check_int(argv[*i]) != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  tetris->map->width = my_getnbr(argv[*i]);
  *i = *i + 1;
  if (check_int(argv[*i]) != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 2, true);
      return (- 1);
    }
  tetris->map->height = my_getnbr(argv[*i]);
  return (0);
}

int	set_map(t_tetris *tetris, int *i, char **argv, bool eq_true)
{
  int	len;

  my_printf("map\n");
  if (eq_true == false)
    return (set_map_m(tetris, i, argv));
  else
    {
      len = my_strlen("--map-size=");
      tetris->map->width = get_cpl_nbr(argv[*i] + len, true);
      tetris->map->height = get_cpl_nbr(argv[*i] + len, false);
      if (tetris->map->width == - 1 || tetris->map->height == - 1)
	{
	  my_putstr_error(ARG_ERR_MSG);
	  my_putnbr_error(*i, true);
	  return (- 1);
	}
    }
  return (0);
}

int	set_w(t_tetris *tetris, int *i, char **argv, bool eq_true)
{
  my_printf("without\n");
  if (eq_true == true && my_strcmp(argv[*i], "--without-next") != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i, true);
      return (- 1);
    }
  tetris->game->next = false;
  return (0);
}
