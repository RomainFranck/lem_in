/*
** test.c for  in /home/cengiz_c/lem_in
**
** Made by Cengiz
** Login   <cengiz_c@epitech.net>
**
** Started on  Wed Apr 23 17:23:23 2014 Cengiz
** Last update Wed Apr 23 17:42:03 2014 Cengiz
*/

#include "nodes.h"
#include <stdlib.h>

void	smashTheAnts(t_ant *queen)
{
  t_ant	*ptr;
  t_ant *tpr;

  ptr = queen;
  while (ptr->next != NULL)
    ptr = ptr->next;
  while (tpr != queen)
    {
      tpr = queen;
      while (tpr->next != ptr)
	tpr = tpr->next;
      free(ptr);
      ptr = tpr;
    }
  free(tpr);
}

t_ant	*antCreate(t_ant *queen, t_nd *position, int i)
{
  t_ant	*ant;
  t_ant	*ptr;

  ptr = queen;
  while (ptr->next != NULL)
    ptr = ptr->next;
  if ((ant = malloc(sizeof(t_ant))) == NULL)
    exit(0);
  ant->number = i;
  ant->node = position;
  ant->next = NULL;
  ptr->next = ant;
  return (queen);
}

t_ant	*releaseTheAnts(int nb, t_nd *position)
{
  int  	i;
  t_ant	*ant;

  i = 2;
  ant = malloc(sizeof(t_ant));
  ant->number = 1;
  ant->node = position;
  ant->next = NULL;
  while (i <= nb)
    {
      ant = antCreate(ant, position, i);
      i++;
    }
  return (ant);
}
