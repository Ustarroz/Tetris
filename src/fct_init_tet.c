/*
** fct_init_tet.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar  4 10:13:01 2016 edouard puillandre
** Last update Sat Mar 12 18:02:50 2016 edouard puillandre
*/

#include "tetris.h"

int	my_map_tab(t_map *map)
{
  int	i;
  int	j;

  if ((map->form = malloc(sizeof(char *) * (map->height + 1))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (- 1);
    }
  i = - 1;
  while (++i < map->height)
    {
      j = - 1;
      if ((map->form[i] = malloc(map->width + 1)) == NULL)
	{
	  my_putstr_error(MALLOC_ERR_MSG);
	  return (- 1);
	}
      while (++j < map->width)
	map->form[i][j] = ' ';
      map->form[i][j] = '\0';
    }
  map->form[i] = NULL;
  return (0);
}

t_map	*my_def_map()
{
  t_map	*map;

  if ((map = malloc(sizeof(t_map))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  map->width = HEIGHT_DEF;
  map->height = WIDTH_DEF;
  map->form = NULL;
  return (map);
}

t_game		*my_def_game()
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  game->next = true;
  game->lvl = 1;
  game->t.min = 0;
  game->t.sec = 0;
  game->score = 0;
  game->high_score = 0;
  return (game);
}

t_tetris	*my_def_tetris(char **env)
{
  t_tetris	*tetris;

  if ((tetris = malloc(sizeof(t_tetris))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  tetris->piece = NULL;
  if ((tetris->nb_piece = files(tetris->piece)) == - 1)
    return (NULL);
  tetris->debug = false;
  if ((tetris->map = my_def_map()) == NULL)
    return (NULL);
  if ((tetris->game = my_def_game()) == NULL)
    return (NULL);
  if (my_def_cmd(tetris, env) == - 1)
    return (NULL);
  return (tetris);
}
