/*
** main.c for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 14:22:50 2014 Romain Franck
** ##Last update Tue Mar 25 16:41:42 2014 Romain Franck
*/

#include <stdio.h>
#include "nodes.h"
#include "lemin.h"

t_nd	*parse()
{
  char	*a;
  t_nd	*nd;

  a = getnextline(0);
  nd = nd_init(a, 0);
  return (nd);
}

int	main()
{
  t_nd	*nd;

  nd = parse();
  puts(nd->name);
  return (0);
}
