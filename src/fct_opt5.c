/*
** fct_opt3.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 16:54:44 2016 edouard puillandre
** Last update Sat Mar 12 11:53:34 2016 edouard puillandre
*/

#include "tetris.h"

int	set_kp_eq(t_tetris *tetris, int *i, char **argv)
{
#ifdef DEBUG
  my_printf("kp eq\n");
#endif
  free(tetris->cmd[ID_KP].key);
  tetris->cmd[ID_KP].key = my_strdup(argv[*i] + my_strlen("--key-pause="));
  if (tetris->cmd[ID_KP].key == NULL)
    return (- 1);
  return (0);
}

int	set_kp(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("kp\n");
#endif
  *i = *i + 1;
  if (*i >= argc)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  free(tetris->cmd[ID_KP].key);
  tetris->cmd[ID_KP].key = my_strdup(argv[*i]);
  if (tetris->cmd[ID_KP].key == NULL)
    return (- 1);
  return (0);
}

int	set_kl_eq(t_tetris *tetris, int *i, char **argv)
{
#ifdef DEBUG
  my_printf("kl eq\n");
#endif
  free(tetris->cmd[ID_KL].key);
  tetris->cmd[ID_KL].key = my_strdup(argv[*i] + my_strlen("--key-left="));
  if (tetris->cmd[ID_KL].key == NULL)
    return (- 1);
  return (0);
}

int	set_kl(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("kl\n");
#endif
  *i = *i + 1;
  if (*i >= argc)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  free(tetris->cmd[ID_KL].key);
  tetris->cmd[ID_KL].key = my_strdup(argv[*i]);
  if (tetris->cmd[ID_KL].key == NULL)
    return (- 1);
  return (0);
}

int	set_kr_eq(t_tetris *tetris, int *i, char **argv)
{
#ifdef DEBUG
  my_printf("kr eq\n");
#endif
  free(tetris->cmd[ID_KR].key);
  tetris->cmd[ID_KR].key = my_strdup(argv[*i] + my_strlen("--key-right="));
  if (tetris->cmd[ID_KR].key == NULL)
    return (- 1);
  return (0);
}
