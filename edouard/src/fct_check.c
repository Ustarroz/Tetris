/*
** fct_check.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 17:14:22 2016 edouard puillandre
** Last update Mon Mar  7 17:42:55 2016 edouard puillandre
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

int	my_check_opt(char **argv, int *k, t_opt opt, t_tetris *tetris)
{
  int	check;

  if (my_strcmp(argv[*k], opt.str) == 0)
    {
      if ((check = opt.fct(tetris, k, argv, false)) != 0)
	return (check);
      else
	return (2);
    }
  if (opt.eq == NULL)
    return (0);
  if (my_strncmp(argv[*k], opt.eq, my_strlen(opt.eq)) == 0)
    {
      if ((check = opt.fct(tetris, k, argv, true)) != 0)
	return (check);
      else
	return (2);
    }
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
      while (end == false && ++i < OPT_LEN)
	if ((check = my_check_opt(argv, &k, opt[i], tetris)) == 2)
	  end = true;
	else if (check != 0)
	  return (check);
      if (i == OPT_LEN)
	{
	  my_putstr_error(ARG_ERR_MSG);
	  my_putnbr_error(k, true);
	  return (- 1);
	}
    }
  return (0);
}
