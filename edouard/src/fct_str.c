/*
** fct_option.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 14:11:01 2016 edouard puillandre
** Last update Fri Mar  4 17:40:40 2016 edouard puillandre
*/

#include "tetris.h"

char	*my_strdup(char *str)
{
  int	len;
  int	i;
  char	*ptr;

  len = my_strlen(str);
  if ((ptr = malloc(len + 1)) == NULL)
    return (NULL);
  i = - 1;
  while (str[++i] != '\0')
    ptr[i] = str[i];
  ptr[i] = '\0';
  return (ptr);
}

int	my_strcmp(char *str, char *ptr)
{
  int	i;

  if (str == NULL)
    return (- 1);
  if (ptr == NULL)
    return (1);
  i = 0;
  while (str[i] != '\0' && ptr[i] != '\0' && str[i] == ptr[i])
    i = i + 1;
  return (str[i] - ptr[i]);
}

int	my_strncmp(char *str, char *ptr, int n)
{
  int	i;

  if (str == NULL)
    return (- 1);
  if (ptr == NULL)
    return (1);
  i = 0;
  while (str[i] != '\0' && ptr[i] != '\0' && str[i] == ptr[i] && i < n - 1)
    i = i + 1;
  return (str[i] - ptr[i]);
}
