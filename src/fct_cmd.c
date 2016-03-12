/*
** fct_cmd.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/PSU_2015_tetris
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Sat Mar 12 11:29:56 2016 edouard puillandre
** Last update Sat Mar 12 11:30:59 2016 edouard puillandre
*/

#include "tetris.h"

int	my_def_cmd(t_tetris *tetris, char **env)
{
  char	*str;

  if ((str = my_find_term(env)) == NULL)
    return (- 1);
  if (setupterm(str, 1, NULL) == - 1)
    return (- 1);
  tetris->cmd[ID_KL].key = my_strdup(tigetstr("kcub1"));
  tetris->cmd[ID_KR].key = my_strdup(tigetstr("kcuf1"));
  tetris->cmd[ID_KT].key = my_strdup(tigetstr("kcuu1"));
  tetris->cmd[ID_KD].key = my_strdup(tigetstr("kcud1"));

  tetris->cmd[ID_KL].key = my_strdup("^EOD");
  tetris->cmd[ID_KR].key = my_strdup("^EOC");
  tetris->cmd[ID_KT].key = my_strdup("^EOA");
  tetris->cmd[ID_KD].key = my_strdup("^EOB");
  tetris->cmd[ID_KQ].key = my_strdup("q");
  tetris->cmd[ID_KP].key = my_strdup(" ");
}
