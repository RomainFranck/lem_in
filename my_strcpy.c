/*
** my_strcpy.c for  in /home/Florian/rendu/CPE_2014_corewar/asm/src
**
** Made by Florian
** Login   <Florian@epitech.net>
**
** Started on  Wed Apr  2 12:40:09 2014 Florian
** Last update Thu Apr 24 16:51:53 2014 Florian
*/

#include "lemin.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_strcpy2(char *head, char *str, int i)
{
  int		n;

  n = 0;
  while (str[n])
    head[i + n] = str[n++];
  return (head);
}
