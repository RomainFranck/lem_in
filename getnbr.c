/*
** getnbr.c for fdf in /home/galleg_a/fdf
** 
** Made by Galleg_a
** Login   <galleg_a@epitech.eu>
** 
** Started on  Sun Dec  8 17:13:16 2013 Galleg_a
** Last update Wed Mar 26 02:03:36 2014 Galleg_a
*/

#include "lemin.h"

int	is_alphaz(char c)
{
  if ((c < '0' || c > '9') && c != '-' && c != '+')
    return (1);
  else
    return (0);
}

int	my_getnbr_aux(int nbr, char *str, int minus)
{
  if (minus % 2 == 1 && (nbr * -1) > 0)
    return (0);
  else if (minus % 2 == 0 && nbr < 0)
    return (0);
  if (str[0] < '0' || str[0] > '9')
    return (nbr);
  nbr = nbr * 10 + (str[0] - 48);
  return (my_getnbr_aux(nbr, str + 1, minus));
}

int	my_getnbr(char *str)
{
  int	minus;
  int	i;

  i = 0;
  minus = 0;
  if (!str)
    return (-1);
  while (str[i] && is_alphaz(str[i]))
    i++;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	minus++;
      i++;
    }
  if (minus % 2 == 0)
    return (my_getnbr_aux(0, str + i, minus));
  else
    return (-my_getnbr_aux(0, str + i, minus));
}
