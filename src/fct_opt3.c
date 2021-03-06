/*
** fct_opt3.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 16:54:44 2016 edouard puillandre
** Last update Thu Mar 17 14:29:09 2016 edouard puillandre
*/

#include "tetris.h"

int	set_kt(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("kt\n");
#endif
  *i = *i + 1;
  if (*i >= argc)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  free(tetris->cmd[ID_KT].key);
  if ((tetris->cmd[ID_KT].key = my_strdup(argv[*i])) == NULL)
    return (- 1);
  if (tetris->cmd[ID_KT].key[0] == '\0')
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  return (0);
}

int	set_kt_eq(t_tetris *tetris, int *i, char **argv)
{
#ifdef DEBUG
  my_printf("kt eq\n");
#endif
  free(tetris->cmd[ID_KT].key);
  tetris->cmd[ID_KT].key = my_strdup(argv[*i] + my_strlen("--key-turn="));
  if (tetris->cmd[ID_KT].key == NULL)
    return (- 1);
  if (tetris->cmd[ID_KT].key[0] == '\0')
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i, true);
      return (- 1);
    }
  return (0);
}

int	set_kd(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("kd\n");
#endif
  *i = *i + 1;
  if (*i >= argc)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  free(tetris->cmd[ID_KD].key);
  if ((tetris->cmd[ID_KD].key = my_strdup(argv[*i])) == NULL)
    return (- 1);
  if (tetris->cmd[ID_KD].key[0] == '\0')
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  return (0);
}

int	set_kd_eq(t_tetris *tetris, int *i, char **argv)
{
#ifdef DEBUG
  my_printf("kd eq\n");
#endif
  free(tetris->cmd[ID_KD].key);
  tetris->cmd[ID_KD].key = my_strdup(argv[*i] + my_strlen("--key-drop="));
  if (tetris->cmd[ID_KD].key == NULL)
    return (- 1);
  if (tetris->cmd[ID_KD].key[0] == '\0')
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i, true);
      return (- 1);
    }
  return (0);
}

int	set_kq(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("kq\n");
#endif
  *i = *i + 1;
  if (*i >= argc)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  free(tetris->cmd[ID_KQ].key);
  tetris->cmd[ID_KQ].key = my_strdup(argv[*i]);
  if (tetris->cmd[ID_KQ].key == NULL)
    return (- 1);
  if (tetris->cmd[ID_KQ].key[0] == '\0')
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  return (0);
}
