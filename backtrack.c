/*
** backtrack.c for lemin in /home/franck_r/rendu/lem_in
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 22:15:52 2014 Romain Franck
** Last update Tue Mar 25 22:15:52 2014 Romain Franck
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lemin.h"
#include "nodes.h"

void	init(t_frm *sen)
{
  t_pn	list;
  t_pth	a;

  a.node = sen->start;
  list.first = &a;
  list.last = &a;
  backtrack(sen, sen->start, &list);
}

void	path(t_pn *list, t_nd *room)
{
  t_pth	*a;

  if ((a = malloc(sizeof(t_pth))) == NULL)
    exit(0);
  a->node = room;
  a->prev = list->last;
  a->next = NULL;
  list->last->next = a;
  list->last = a;
}

void	noway(t_pn *list)
{
  list->last = list->last->prev;
  free(list->last->next);
  list->last->next = NULL;
}
void	backtrack(t_frm *sen, t_nd *room, t_pn *list)
{
  t_pth	*ptr;
  int	i;

  path(list, room);
  if (room == sen->exit)
    {
      ptr = list->last;
      i = 0;
      while (ptr != list->first)
	{
	  ptr->node->weight = WEIGHT(ptr->node->weight, i);
	  printf("Node : %s is %d ", ptr->node->name, ptr->node->weight);
	  ptr = ptr->prev;
	  i++;
	}
      printf("\n");
    }
  i = -1;
  while (room->links[++i] != NULL)
    if (!pth_find(list, room->links[i]))
      backtrack(sen, room->links[i], list);
  noway(list);
  return ;
}

void	cleaningWoman(t_frm *sen)
{
  t_nd	*ptr;

  ptr = sen->first;
  while (ptr != sen->last)
    {
      ptr->full = 0;
      ptr = ptr->next;
    }
  ptr->full = 0;
}

int	move(t_ant *ant)
{
  int	i;
  t_nd	*n;
  t_nd	*p;

  i = 0;
  if (ant->node->weight == 0)
    return (0);
  n = ant->node->links[i];
  while (ant->node->links[i] != NULL)
    {
      p = ant->node->links[i];
      n = (NODE(p) < NODE(n) ? p : n);
      i++;
    }
  n->full += 1;
  if ((n->weight == 0) || (n->full == 1 && NODE(n) <= ant->node->weight))
    {
      ant->node->full = 0;
      ant->node = n;
      printf("P%d-%s ", ant->number, n->name);
      return (1);
    }
  return (1);
}

int	antAction(t_ant *ant, int (*Action)(t_ant*))
{
  int	i;
  t_ant	*ptr;

  i = 0;
  ptr = ant;
  while (ptr != NULL)
    {
      i |= Action(ptr);
      ptr = ptr->next;
    }
  if (i != 0)
    printf("\n");
  return (i);
}
