/*
** nodes.h for lem_in in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 11:09:02 2014 Romain Franck
** Last update Tue Mar 25 21:12:06 2014 Galleg_a
*/

#ifndef NODES_H_
# define NODES_H_

typedef struct	s_node
{
  struct s_node	*prev;
  char		*name;
  char		type;
  //int		dist;
  char		full;
  struct s_node	*links;
  struct s_node	*next;
} t_nd;

/*
** Définir l'emplacement de la fourmi selon le node ou la fourmi ?
*/

typedef struct	s_ant
{
  int		number;
  t_nd		*node;
  struct s_ant	*next;
} t_ant;

#endif
