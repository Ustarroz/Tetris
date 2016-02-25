/*
** my_strlen.c for Piscine_J_04 in /home/puilla_e/Day4
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Oct  1 22:34:42 2015 edouard puillandre
** Last update Tue Oct  6 18:10:04 2015 edouard puillandre
*/

int	my_strlen(char *str)
{
  int	var_one;

  var_one = 0;
  while (*str != '\0')
    {
      var_one = var_one + 1;
      str = str + 1;
    }
  return (var_one);
}
