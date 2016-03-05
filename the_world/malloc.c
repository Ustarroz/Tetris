/*
** malloc.c for tetris in /home/voyevoda/rendu/systeme_unix/PSU_2015bstetris
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Thu Mar  3 15:54:35 2016 Voyevoda
** Last update Fri Mar  4 18:08:53 2016 Voyevoda
*/

#include "../include/tetris.h"
void	malloc_piece(t_piece *alphabet)
{
  int	i;

  i = 0;
  alphabet->shape = malloc(sizeof(char) * (alphabet->height));
    while (i < alphabet->height)
      alphabet->shape[i++] = malloc(sizeof(alphabet->width));
}
