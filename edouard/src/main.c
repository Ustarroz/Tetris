/*
** main.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Feb 25 18:46:48 2016 edouard puillandre
** Last update Thu Mar 10 16:30:09 2016 edouard puillandre
*/

#include "tetris.h"

int	start_tetris(int argc, char **argv, t_tetris *tetris)
{
  int	check;

  if ((check = my_check_arg(argc, argv, tetris)) == 1)
    {
      my_free_tetris(tetris, false);
      return (1);
    }
  else if (check == - 1)
    {
      my_free_tetris(tetris, false);
      return (- 1);
    }
  if (my_map_tab(tetris->map) == - 1)
    return (- 1);
  if (tetris->debug == true)
    my_print_debug(tetris);
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_tetris	*tetris;
  int		check;

  if ((tetris = my_def_tetris(env)) == NULL)
    return (- 1);
  if ((check = start_tetris(argc, argv, tetris)) == 1)
    return (0);
  else if (check ==- 1)
    return (- 1);
  my_free_tetris(tetris, true);
  return (0);
}
