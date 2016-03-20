/*
** fct_parsing2.c for tetris in /home/voyevoda/rendu/systeme_unix/PSU_2015_tetris/src
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Sun Mar 20 13:51:37 2016 Voyevoda
** Last update Sun Mar 20 22:47:40 2016 Voyevoda
*/

#include "tetris.h"

char	*epur_star(char *str)
{
  int	i;
  int	k;

  i = -1;
  k = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '*')
	k = i;
      if (str[i + 1] == '\0' && k != -1)
	str[k + 1] = '\0';
    }
  return (str);
}
