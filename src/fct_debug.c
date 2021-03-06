/*
** fct_debug.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Mar  8 09:33:56 2016 edouard puillandre
** Last update Sat Mar 19 23:48:42 2016 edouard puillandre
*/

#include "tetris.h"

void	my_print_piece(t_piece *tmp)
{
  int	x;

  my_printf("Size %d*%d : Color %d :\n", tmp->width, tmp->height, tmp->col);
  x = - 1;
  while (++x < tmp->height)
    my_printf("%s\n", tmp->shape[x]);
}

void		my_print_tetrimino(t_tetris *tetris)
{
  int		i;
  int		j;
  int		len;
  int		end;
  t_piece	*tmp;

  i = - 1;
  tmp = tetris->piece;
  len = my_strlen("./tetriminos/");
  end = my_strlen(".tetrimino");
  while (++i < tetris->nb_piece)
    {
      my_printf("Tetriminos : Name ");
      j = len - 1;
      while (tmp->name[++j + end] != '\0')
	my_printf("%c", tmp->name[j]);
      my_printf(" : ");
      if (tmp->valid)
	my_print_piece(tmp);
      else
	my_printf("Error\n");
      tmp = tmp->next;
    }
}

void	my_str_space(char *text, char *str)
{
  int	i;

  i = - 1;
  my_printf(text);
  while (str[++i] != '\0')
    if (str[i] == ' ')
      my_printf("(space)");
    else if (str[i] == 27)
      my_printf("^E");
    else
      my_printf("%c", str[i]);
  my_printf("\n");
}

void	my_print_data(t_tetris *tetris)
{
  my_printf("*** DEBUG MODE ***\n");
  my_str_space("Key Left : ", tetris->cmd[ID_KL].key);
  my_str_space("Key Right : ", tetris->cmd[ID_KR].key);
  my_str_space("Key Turn : ", tetris->cmd[ID_KT].key);
  my_str_space("Key Drop : ", tetris->cmd[ID_KD].key);
  my_str_space("Key Quit : ", tetris->cmd[ID_KQ].key);
  my_str_space("Key Pause : ", tetris->cmd[ID_KP].key);
  my_printf("Next : %s\n", (tetris->next->valid) ? "Yes" : "No");
  my_printf("Level : %d\n", tetris->game->lvl);
  my_printf("Size : %d*%d\n", tetris->map->height, tetris->map->width);
  my_printf("Tetriminos : %d\n", tetris->nb_piece);
  my_print_tetrimino(tetris);
  my_printf("Press a key to start Tetris\n");
}

int			my_print_debug(t_tetris *tetris)
{
  char			buff[1];
  struct termios	termios_p;
  struct termios	save;

  my_print_data(tetris);
  if (ioctl(0, TCGETS, &save) == - 1)
    return (- 1);
  termios_p = save;
  termios_p.c_lflag = ~ (ICANON | ECHO);
  termios_p.c_cc[VMIN] = 1;
  termios_p.c_cc[VTIME] = 0;
  if (ioctl(0, TCSETS, &termios_p) == - 1)
    return (- 1);
  if (read(1, buff, 1) == - 1)
    return (- 1);
  if (ioctl(0, TCSETS, &save) == - 1)
    return (- 1);
  return (0);
}
