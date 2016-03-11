/*
** fct_init_tet.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar  4 10:13:01 2016 edouard puillandre
** Last update Thu Mar 10 16:27:23 2016 edouard puillandre
*/

#include "tetris.h"

int	my_map_tab(t_map *map)
{
  int	i;
  int	j;

  if ((map->tab = malloc(sizeof(char *) * (map->height + 1))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (- 1);
    }
  i = - 1;
  while (++i < map->height)
    {
      j = - 1;
      if ((map->tab[i] = malloc(map->width + 1)) == NULL)
	{
	  my_putstr_error(MALLOC_ERR_MSG);
	  return (- 1);
	}
      while (++j < map->width)
	map->tab[i][j] = ' ';
      map->tab[i][j] = '\0';
    }
  map->tab[i] = NULL;
  return (0);
}

t_map	*my_def_map()
{
  t_map	*map;

  if ((map = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  map->width = HEIGHT_DEF;
  map->height = WIDTH_DEF;
  return (map);
}

t_game		*my_def_game()
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->next = true;
  game->lvl = 1;
  game->t.min = 0;
  game->t.sec = 0;
  game->score = 0;
  game->high_score = 0;
  return (game);
}

void	my_def_cmd(t_tetris *tetris)
{
  tetris->cmd[ID_KL].key = my_strdup("^EOD");
  tetris->cmd[ID_KR].key = my_strdup("^EOC");
  tetris->cmd[ID_KT].key = my_strdup("^EOA");
  tetris->cmd[ID_KD].key = my_strdup("^EOB");
  tetris->cmd[ID_KQ].key = my_strdup("q");
  tetris->cmd[ID_KP].key = my_strdup(" ");
}

t_tetris	*my_def_tetris(char **env)
{
  t_tetris	*tetris;

  (void) env;
  if ((tetris = malloc(sizeof(t_tetris))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  tetris->debug = false;
  if ((tetris->map = my_def_map()) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  if ((tetris->game = my_def_game()) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  my_def_cmd(tetris);
  return (tetris);
}
