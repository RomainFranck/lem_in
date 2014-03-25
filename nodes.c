/*
** nodes.c for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 12:21:39 2014 Romain Franck
** Last update Tue Mar 25 12:21:39 2014 Romain Franck
*/

#include <stdlib.h>
#include "nodes.h"
#include "lemin.h"

t_nd	*nd_find(t_nd *f, char *name)
{
  t_nd	*ptr;

  ptr = f;
  while (my_strcmp(ptr->name, name) == 0 && ptr->next != NULL)
    ptr = ptr->next;
  return (ptr);
}

t_nd	*nd_find_tab(t_tn *f, char *name)
{
  int	i;

  i = 0;
  while (my_strcmp(f[i]->name, name) == 0 && f[i + 1] != NULL)
    i++;
  return (f[i]);
}
