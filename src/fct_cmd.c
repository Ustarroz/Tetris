/*
** fct_cmd.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/PSU_2015_tetris
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Sat Mar 12 11:29:56 2016 edouard puillandre
** Last update Sat Mar 12 12:32:31 2016 edouard puillandre
*/

#include "tetris.h"

char	*my_find_term(char **env)
{
  char	*str;
  int	i;
  bool	end;

  i = - 1;
  end = false;
  while(end == false && env[++i] != NULL)
    if (my_strncmp(env[i], ENV_TERM, 5) == 0)
      end = true;
  if ((str = my_strdup(env[i] + my_strlen(ENV_TERM))) == NULL)
    return (NULL);
  return (str);
}

char	*get_keypad(char *cap)
{
  char	*str;

  if ((str = tigetstr(cap)) == NULL)
    {
      my_putstr_error(CAP_ERR_MSG);
      return (NULL);
    }
  my_printf("%s\n", str);
  if ((str = my_strdup(str)) == NULL)
    return (NULL);
  return (str);
}

int	my_def_cmd(t_tetris *tetris, char **env)
{
  char	*str;

  if ((str = my_find_term(env)) == NULL)
    return (- 1);
  if (setupterm(str, 1, NULL) == - 1)
    return (- 1);
  if ((tetris->cmd[ID_KL].key = get_keypad("kcub1")) == NULL)
    return (- 1);
  if ((tetris->cmd[ID_KR].key = get_keypad("kcuf1")) == NULL)
    return (- 1);
  if ((tetris->cmd[ID_KT].key = get_keypad("kcuu1")) == NULL)
    return (- 1);
  if ((tetris->cmd[ID_KD].key = get_keypad("kcud1")) == NULL)
    return (- 1);
  tetris->cmd[ID_KQ].key = my_strdup("q");
  tetris->cmd[ID_KP].key = my_strdup(" ");
  free(str);
  return (0);
}
