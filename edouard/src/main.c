/*
** main.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Feb 25 18:46:48 2016 edouard puillandre
** Last update Thu Mar  3 11:24:56 2016 edouard puillandre
*/

#include "tetris.h"

int	main(int argc, char **argv)
{
  bool	n;
  (void) argc;
  (void) argv;

  n = false;
  if (n)
    write(1, "yes", 3);
  else
    write(1, "no", 2);
  return (0);
}
