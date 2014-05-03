/*
** backtrack.c for lemin in /home/franck_r/rendu/lem_in
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 22:15:52 2014 Romain Franck
** Last update Fri May  2 14:19:52 2014 root
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
  if (sen->last == room)
    {
      ptr = list->last;
      i = 0;
      while (ptr != list->first)
	{
	  /*printf("%d, %d\n", ptr->node->weight, i);*/
	  ptr->node->weight = WEIGHT(ptr->node->weight, i++);
	  ptr = ptr->prev;
}
    }
  i = -1;
  while (room->links[++i] != NULL)
    if (!pth_find(list, room->links[i]))
      backtrack(sen, room->links[i], list);
  noway(list);
  return ;
}

int	move(t_ant *ant)
{
  int	i;
  t_nd	*n;

  i = 0;
  n = ant->node->links[i];
  while (ant->node->links[i] != NULL)
    {
      n = (ant->node->links[i]->weight < n->weight ? ant->node->links[i] : n);
      i++;
    }
  n->full++;
  if (n->full == 1)
    {
      printf("P%d-%s", ant->number, ant->node->name); /*--my_printf--*/
      ant->node->full--;
      ant->node = n;
      printf("P%d-%s", ant->number, n->name); /*--my_printf--*/
    }
  if (ant->node->weight == 0)
    return (0);
  return (1);
}

int	antAction(t_ant *ant, int (*Action)(t_ant*))
{
  int	i;
  t_ant	*ptr;

  i = 0;
  ptr = ant;
  i |= Action(ptr);
  ptr = ptr->next;
  while (ptr != NULL)
    {
      printf(" ");
      i |= Action(ptr);
      ptr = ptr->next;
    }
  sleep(1);
  printf("\n");
  return (i);
}
