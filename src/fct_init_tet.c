/*
** fct_init_tet.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar  4 10:13:01 2016 edouard puillandre
** Last update Thu Mar 17 14:04:20 2016 edouard puillandre
*/

#include "tetris.h"

void		my_put_pos(t_tetris *tetris)
{
  int		width;
  t_piece	*tmp;

  width = MAP_POS_X - (GAME_POS_X + tetris->game->width);
  tetris->game->x = GAME_POS_X;
  tetris->game->y = GAME_POS_Y;
  tetris->map->pos_x = MAP_POS_X;
  tetris->map->pos_y = MAP_POS_Y;
  tetris->next->x = MAP_POS_X + width + tetris->map->width;
  tetris->next->y = MAP_POS_Y;
  tmp = tetris->piece;
  tetris->next->width = tmp->width;
  tetris->next->height = tmp->height;
  while (tmp->next != tetris->piece)
    {
      if (tmp->height > tetris->next->height)
	tetris->next->height = tmp->height;
      if (tmp->width > tetris->next->width)
	tetris->next->width = tmp->width;
      tmp = tmp->next;
    }
  tetris->next->width = tetris->next->width + 4;
  tetris->next->height = tetris->next->height + 5;
  tetris->game->t = time(NULL);
}

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
  game->lvl = 1;
  game->score = 0;
  game->high_score = 0;
  game->width = GAME_WIDTH;
  game->height = GAME_HEIGHT;
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
  if ((tetris->nb_piece = files(&(tetris->piece))) == - 1)
    return (NULL);
  tetris->debug = false;
  if ((tetris->map = my_def_map()) == NULL)
    return (NULL);
  if ((tetris->next = malloc(sizeof(t_next))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  tetris->next->valid = true;
  if ((tetris->game = my_def_game()) == NULL)
    return (NULL);
  if (my_def_cmd(tetris, env) == - 1)
    return (NULL);
  return (tetris);
}
