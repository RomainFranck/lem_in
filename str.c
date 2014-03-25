/*
** str.c for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 12:28:20 2014 Romain Franck
** Last update Tue Mar 25 12:28:20 2014 Romain Franck
*/

#include <stdlib.h>

int	my_strcmp(char *a, char *b)
{
  return (*a == *b ? *a ? my_strcmp(a + 1, b + 1) : 1 : 0);
}

int	my_strlen(char *s, int i)
{
  return (*(s + i) && *(s + i) != '-' && *(s + i) != 10 && *(s + i) != 32
	  ? 1 + my_strlen(s + 1, i) : 1);
}

char	*my_strdup(char *s, int i)
{
  char	*r;
  int	a;

  a = 0;
  if ((r = malloc(my_strlen(s, i))) == NULL)
    return (NULL);
  while (s[i + a] && s[a + i] != '-' && s[i + a] != 10 && s[i + a] != 32)
    {
      r[a] = s[i + a];
      a++;
    }
  r[a] = 0;
  return (r);
}
