/*
** getnextline.c for getnextline in /home/franck_r/rendu/getnextline
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Sun Mar  9 18:42:52 2014 Romain Franck
** Last update Thu May  1 05:38:33 2014 Galleg_a
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"

#define BUF_SIZE 4096

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_realloc(char *buff)
{
  char	*buf2;

  if (buff == 0)
    {
      if ((buf2 = malloc(sizeof(char) * (BUF_SIZE + 1))) == NULL)
	return (NULL);
    }
  else
    {
      if ((buf2 = malloc(sizeof(char) *
			 (my_strlen_no_troll(buff) + BUF_SIZE + 1))) == 0)
	return (NULL);
      my_strcpy(buf2, buff);
      free(buff);
    }
  return (buf2);
}

char	*norme_get_next(int *i, char *str, int j)
{
  (*i)++;
  str[j] = 0;
  return (str);
}

char		*getnextline(int fd)
{
  static char	buff[BUF_SIZE + 1];
  static int	i;
  int		j;
  char		*str;
  int		len;

  if ((j = 0) == 0 && (str = malloc(sizeof(char) * (BUF_SIZE + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (1)
    {
      if (buff[i] == '\0')
	{
	  str[j] = '\0';
	  str = my_realloc(str);
	  if ((len = read(fd, buff, BUF_SIZE)) == 0)
	    return (str[0] != 0) ? (str) : (0);
	  if ((i = 0) == 0 && len < 0)
	    return (0);
	  buff[len] = 0;
	}
      if (buff[i] == '\n')
	return (norme_get_next(&i, str, j));
      str[j++] = buff[i++];
    }
}
