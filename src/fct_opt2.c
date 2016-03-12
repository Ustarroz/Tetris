/*
** fct_opt2.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 16:51:51 2016 edouard puillandre
** Last update Sat Mar 12 11:50:48 2016 edouard puillandre
*/

#include "tetris.h"

int	set_lvl_eq(t_tetris *tetris, int *i, char **argv)
{
  int	len;

#ifdef DEBUG
  my_printf("lvl eq\n");
#endif
  len = my_strlen("--level=");
  if (check_int(argv[*i] + len) != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i, true);
      return (- 1);
    }
  tetris->game->lvl = my_getnbr(argv[*i] + len);
  return (0);
}

int	set_lvl(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("lvl\n");
#endif
  *i = *i + 1;
  if (*i >= argc || check_int(argv[*i]) != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1); 
    }
  tetris->game->lvl = my_getnbr(argv[*i]);
  return (0);
}

int	set_debug_eq(t_tetris *tetris, int *i, char **argv)
{
#ifdef DEBUG
  my_printf("debug eq\n");
#endif
  if (my_strcmp(argv[*i], "--debug") != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i, true);
      return (- 1);
    }
  tetris->debug = true;
  return (0);
}

int	set_debug(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("debug\n");
#endif
  (void) i;
  (void) argv;
  (void) argc;
  tetris->debug = true;
  return (0);
}

int	set_kq_eq(t_tetris *tetris, int *i, char **argv)
{
#ifdef DEBUG
  my_printf("kq eq\n");
#endif
  free(tetris->cmd[ID_KQ].key);
  tetris->cmd[ID_KQ].key = my_strdup(argv[*i] + my_strlen("--key-quit="));
  if (tetris->cmd[ID_KQ].key == NULL)
    return (- 1);
  return (0);
}
