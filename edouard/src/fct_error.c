/*
** fct_error.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Sat Mar  5 14:16:24 2016 edouard puillandre
** Last update Sat Mar  5 16:16:18 2016 edouard puillandre
*/

#include "tetris.h"

void	my_putnbr_error(int nb, bool first)
{
  char	c;

  if (nb != 0 && first)
    {
      c = nb % 10 + 48;
      my_putnbr_error(nb / 10, false);
      write(2, &c, 1);
    }
  if (first)
    {
      c= '\n';
      write(2, &c, 1);
    }
}
