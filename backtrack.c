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

void	backtrack(t_frm *sen, t_nd *room, int i)
{
  int	j;

  room->weight = i;
  j = 0;
  while (room->links[j] != NULL)
    {
      if ((room->links[j]->weight > i + 1) ||
	  (room->links[j]->weight == 0 && room->links[j] != sen->exit))
	backtrack(sen, room->links[j], i + 1);
      j++;
    }
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

int	soil(t_ant *ant)
{
  ant->node->full = 1;
  return (0);
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
