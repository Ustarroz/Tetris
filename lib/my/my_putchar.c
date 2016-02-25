/*
** my_putchar.c for Piscine_C_J07 in /home/puilla_e/Day7/lib/my
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Tue Oct  6 17:53:24 2015 edouard puillandre
** Last update Fri Nov 13 13:56:51 2015 edouard puillandre
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
