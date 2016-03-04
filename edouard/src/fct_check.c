/*
** fct_check.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 17:14:22 2016 edouard puillandre
** Last update Fri Mar  4 16:08:47 2016 edouard puillandre
*/

#include "tetris.h"

int	check_int(char *str)
{
  int	i;

  i = - 1;
  while (str[++i] != '\0')
    if (str[i] < '0' || str[i] > '9')
      return (- 1);
  if ((my_strlen(str) == my_strlen(INT_MAX) && my_strcmp(str, INT_MAX)) ||
      my_strlen(str) > my_strlen(INT_MAX))
    return (- 1);
  return (0);
}

int	my_check_arg(int argc, char **argv, t_tetris *tetris)
{
  int	k;
  int	i;
  bool	end;
  int	check;
  t_opt	opt[OPT_LEN];

  k = 0;
  init_tab_opt(opt);
  while (++k < argc)
    {
      end = false;
      i = - 1;
      while (++i < OPT_LEN && end == false)
	if (strcmp(argv[k], opt[i].str) == 0 ||
	    strcmp(argv[k], opt[i].eq, my_strlen(opt[i].eq)) == 0)
	  {
	    if ((check = opt[i].fct(tetris, &k, argv)) != 0)
	      return (check);
	    end = true;
	  }
      if (i == OPT_LEN)
	return (- 1);
    }
  return (0);
}
