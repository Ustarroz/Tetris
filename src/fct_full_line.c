/*
** fct_full_line.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Sun Mar 20 23:16:55 2016 edouard puillandre
** Last update Sun Mar 20 23:39:12 2016 edouard puillandre
*/

#include "tetris.h"

int	check_one_line(int *line, int width)
{
  int	i;

  i = - 1;
  while (++i < width)
    if (line[i] == - 1)
      return (- 1);
  return (1);
}

int	translate_all(t_map *map, int y)
{
  int	i;
  int	x;

  i = y + 1;
  while (--i > 0)
    {
      x = - 1;
      while (++x < map->width)
	map->col[i][x] = map->col[i - 1][x];
    }
  x = - 1;
  while (++x < map->width)
    map->col[i][x] = - 1;
  return (0);
}

int	check_full_line(t_tetris *tetris)
{
  int	y;
  int	line;

  y = - 1;
  line = 0;
  while (++y < tetris->map->width + 2)
    {
      if (check_one_line(tetris->map->col[y], tetris->map->width) == 1)
	{
	  line = line + 1;
	  translate_all(tetris->map, y);
	}
    }
  tetris->game->score = tetris->game->score + line * (line + 1);
  return (0);
}
