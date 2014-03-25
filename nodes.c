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

t_nd	*nd_init(char *name, char type)
{
  t_nd	*nd;

  if ((nd = malloc(sizeof(t_nd))) == NULL)
    return (NULL);
  nd->name = my_strdup(name, 0);
  nd->type = type;
  nd->dist = -1;
  nd->path = NULL;
  nd->prev = NULL;
  nd->next = NULL;
  return (nd);
}

t_nd	*nd_add(t_nd *f, char *name, char type)
{
  t_nd	*nd;
  t_nd	*ptr;

  if ((nd = malloc(sizeof(t_nd))) == NULL)
    return (NULL);
  nd->name = my_strdup(name, 0);
  nd->type = type;
  nd->dist = -1;
  nd->path = NULL;
  nd->next = NULL;
  ptr = f;
  nd->prev = ptr;
  while (ptr->next != NULL)
    ptr = ptr->next;
  ptr->next = nd;
  return (f);
}

t_nd	*nd_find(t_nd *f, char *name)
{
  t_nd	*ptr;

  ptr = f;
  while (my_strcmp(ptr->name, name) == 0 && ptr != NULL)
    ptr = ptr->next;
  return (ptr);
}

t_nd	*tn_link(t_nd *f, char *a, char *b)
{
  t_tn	*tn;
  t_tn	*tnptr;
  t_nd	*ptr;

  if ((tn = malloc(sizeof(t_tn))) == NULL)
    return (NULL);
  tn->exit = nd_find(f, b);
  tn->trafic = 0;
  tn->next = NULL;
  ptr = nd_find(f, a);
  tnptr = ptr->path;
  if (tnptr == NULL)
    ptr->path = tn;
  else
    {
      while (tnptr->next != NULL)
	tnptr = tnptr->next;
      tnptr->next = tn;
    }
  return (f);
}

t_nd	*tn_add(t_nd *f, char *name)
{
  char	*a;
  char	*b;

  a = my_strdup(name, 0);
  b = my_strdup(name, my_strlen(a, 0));
  f = tn_link(f, a, b);
  f = tn_link(f, b, a);
  free(a);
  free(b);
  return (f);
}
