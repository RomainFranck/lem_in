/*
** getnextline.c for getnextline in /home/franck_r/rendu/getnextline
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Sun Mar  9 18:42:52 2014 Romain Franck
** Last update Sun Mar  9 19:35:23 2014 Romain Franck
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*scat(char *a, char b)
{
  int	i;
  char	*c;

  i = 0;
  while (a[i++]);
  if ((c = malloc(1 + i * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (a[i])
    {
      c[i] = a[i];
      i++;
    }
  c[i] = b;
  c[i + 1] = 0;
  free(a);
  return (c);
}

char	*getnextline(int fd)
{
  char	*a;
  char	b;

  if ((a = malloc(sizeof(char))) == NULL)
    return (NULL);
  *a = 0;
  read(fd, &b, 1);
  while ((b != 10) && (b != 0))
    {
      if ((a = scat(a, b)) == NULL)
	return (NULL);
      read(fd, &b, 1);
    }
  return (a);
}
