/*
** main.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Feb 25 18:46:48 2016 edouard puillandre
** Last update Sat Mar  5 16:56:38 2016 edouard puillandre
*/

#include "tetris.h"

int		main(int argc, char **argv, char **env)
{
  t_tetris	*tetris;
  int		check;

  if ((tetris = my_def_tetris(argc, env)) == NULL)
    return (- 1);
  if ((check = my_check_arg(argc, argv, tetris)) == 1)
    return (0);
  else if (check == - 1)
    return (- 1);
  if (my_map_tab(tetris->map) == - 1)
    return (- 1);
  return (0);
}
