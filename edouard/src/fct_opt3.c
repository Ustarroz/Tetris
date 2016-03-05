/*
** fct_opt3.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 16:54:44 2016 edouard puillandre
** Last update Sat Mar  5 16:19:21 2016 edouard puillandre
*/

#include "tetris.h"

int	set_kt(t_tetris *tetris, int *i, char **argv, bool eq_true)
{
  if (eq_true == false)
    {
      *i = *i + 1;
      if (*i > tetris->nb_opt)
	{
	  my_putstr_error(ARG_ERR_MSG);
	  my_putnbr_error(*i - 1, true);
	  return (- 1);
	}
      tetris->cmd[ID_KT].key = my_strdup(argv[*i]);
    }
  else
    tetris->cmd[ID_KT].key = my_strdup(argv[*i] + my_strlen("--key-turn="));
  return (0);
}

int	set_kd(t_tetris *tetris, int *i, char **argv, bool eq_true)
{
  if (eq_true == false)
    {
      *i = *i + 1;
      if (*i > tetris->nb_opt)
	{
	  my_putstr_error(ARG_ERR_MSG);
	  my_putnbr_error(*i - 1, true);
	  return (- 1);
	}
      tetris->cmd[ID_KD].key = my_strdup(argv[*i]);
    }
  else
    tetris->cmd[ID_KD].key = my_strdup(argv[*i] + my_strlen("--key-drop="));
  return (0);
}

int	set_kq(t_tetris *tetris, int *i, char **argv, bool eq_true)
{
  if (eq_true == false)
    {
      *i = *i + 1;
      if (*i > tetris->nb_opt)
	{
	  my_putstr_error(ARG_ERR_MSG);
	  my_putnbr_error(*i - 1, true);
	  return (- 1);
	}
      tetris->cmd[ID_KQ].key = my_strdup(argv[*i]);
    }
  else
    tetris->cmd[ID_KQ].key = my_strdup(argv[*i] + my_strlen("--key-quit="));
  return (0);
}

int	set_kp(t_tetris *tetris, int *i, char **argv, bool eq_true)
{
  if (eq_true == false)
    {
      *i = *i + 1;
      if (*i > tetris->nb_opt)
	{
	  my_putstr_error(ARG_ERR_MSG);
	  my_putnbr_error(*i - 1, true);
	  return (- 1);
	}
      tetris->cmd[ID_KP].key = my_strdup(argv[*i]);
    }
  else
    tetris->cmd[ID_KP].key = my_strdup(argv[*i] + my_strlen("--key-pause="));
  return (0);
}

int	set_debug(t_tetris *tetris, int *i, char **argv, bool eq_true)
{
  if (eq_true && my_strcmp(argv[*i], "--debug") != 0)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i, true);
      return (- 1);
    }
  tetris->debug = true;
  return (0);
}
