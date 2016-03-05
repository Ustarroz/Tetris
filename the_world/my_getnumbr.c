/*
** my_getnumbr.c for minitalk in /home/voyevoda/rendu/systeme_unix/PSU_2015_minitalk/client
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Tue Feb  9 12:14:20 2016 Voyevoda
** Last update Tue Feb  9 12:18:10 2016 Voyevoda
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	operator;

  nb = 0;
  operator = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	operator = - operator;
      str++;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      if (nb > 214748364)
	return (0);
      if (nb == 214748364 && *str > 7 && operator == 1)
	return (0);
      if (nb == 214748364 && *str > 8 && operator == -1)
	return (0);
      nb = nb * 10 + *str - 48;
      str++;
    }
  if (operator == -1)
    nb = - nb;
  return (nb);
}
