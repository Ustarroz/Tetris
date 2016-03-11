/*
** get_next_line.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar 11 12:26:18 2016 edouard puillandre
** Last update Fri Mar 11 12:26:23 2016 edouard puillandre
*/

#include "tetris.h"

int	len_str(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    {
      i = i + 1;
    }
  return (i);
}

char	*my_realloc(char *str, char *buff)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (str != NULL)
    {
      tmp = str;
      str = malloc(sizeof(char *) * (len_str(buff) + len_str(tmp) + 1));
      if (str == NULL)
	return (NULL);
      while (tmp[i] != '\0')
	{
	  str[i] = tmp[i];
	  i = i + 1;
	}
      free(tmp);
    }
  else if ((str = malloc(sizeof(char *) * (len_str(buff) + 1))) == NULL)
    return (NULL);
  while (buff[j] != '\0' && buff[j] != '\n')
    str[i++] = buff[j++];
  str[i] = '\0';
  return (str);
}

int	check_line(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (1);
      i = i + 1;
    }
  return (0);
}

int	buff_next(char *buff)
{
  int	i;
  int	pos;

  i = pos = 0;
  while (buff[pos] != '\n' && buff[pos] != '\0')
    pos = pos + 1;
  if (buff[pos] != '\0')
    pos = pos + 1;
  while (buff[i + pos] != '\0')
    {
      buff[i] = buff[i + pos];
      i = i + 1;
    }
  buff[i] = '\0';
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1] = {0};
  char		*str;
  static int	ret = 1;

  str = NULL;
  if (ret != 0 && buff[0] != '\0')
    {
      buff_next(buff);
      if ((str = my_realloc(str, buff)) == NULL)
	return (NULL);
    }
  while (check_line(buff) == 0 && (ret = read(fd, buff, READ_SIZE)) > 0)
    {
      buff[ret] = '\0';
      if ((str = my_realloc(str, buff)) == NULL)
	return (NULL);
    }
  if (ret == - 1)
    return (NULL);
  if (ret == 0 && str != NULL && str[0] == '\0')
    {
      free(str);
      return (NULL);
    }
  return (str);
}
