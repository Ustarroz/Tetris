/*
** fct_cmd.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/PSU_2015_tetris
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Sat Mar 12 11:29:56 2016 edouard puillandre
** Last update Sun Mar 20 02:32:19 2016 edouard puillandre
*/

#include "tetris.h"

int	my_putchar_bis(int c)
{
  write(1, &c, 1);
  return (0);
}

int	my_find_term(char **env)
{
  char	*str;
  int	i;
  bool	end;

  i = - 1;
  end = false;
  while (end == false && env[++i] != NULL)
    if (my_strncmp(env[i], ENV_TERM, 5) == 0)
      end = true;
  if (end == false)
    return (- 1);
  if ((str = my_strdup(env[i] + my_strlen(ENV_TERM))) == NULL)
    return (- 1);
  if (setupterm(str, 1, NULL) == - 1)
    return (- 1);
  free(str);
  return (0);
}

char	*get_keypad(char *cap)
{
  char	*str;
  char	*ptr;

  if ((str = tigetstr(cap)) == NULL)
    {
      my_putstr_error(CAP_ERR_MSG);
      return (NULL);
    }
  if ((ptr = my_strdup(str)) == NULL)
    return (NULL);
  return (ptr);
}

void	att_cmd_func(t_tetris *tetris)
{
  tetris->cmd[ID_KL].fct = (&fct_left);
  tetris->cmd[ID_KR].fct = (&fct_right);
  tetris->cmd[ID_KT].fct = (&fct_turn);
  tetris->cmd[ID_KD].fct = (&fct_drop);
  tetris->cmd[ID_KQ].fct = (&fct_quit);
  tetris->cmd[ID_KP].fct = (&fct_pause);
}

int	my_def_cmd(t_tetris *tetris, char **env)
{
  if (my_find_term(env) == - 1)
    return (- 1);
  if ((tetris->cmd[ID_KL].key = get_keypad("kcub1")) == NULL)
    return (- 1);
  if ((tetris->cmd[ID_KR].key = get_keypad("kcuf1")) == NULL)
    return (- 1);
  if ((tetris->cmd[ID_KT].key = get_keypad("kcuu1")) == NULL)
    return (- 1);
  if ((tetris->cmd[ID_KD].key = get_keypad("kcud1")) == NULL)
    return (- 1);
  if ((tetris->cmd[ID_KQ].key = my_strdup("q")) == NULL)
    return (- 1);
  if ((tetris->cmd[ID_KP].key = my_strdup(" ")) == NULL)
    return (- 1);
  att_cmd_func(tetris);
  del_curterm(cur_term);
  return (0);
}
