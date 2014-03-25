/*
** nodes.h for lem_in in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 11:09:02 2014 Romain Franck
** ##Last update Tue Mar 25 14:45:43 2014 Romain Franck
*/

#ifndef NODES_H_
#define NODES_H_

typedef struct s_node
{
  char		*name;
  char		type;
  int		dist;
  struct s_tunl	*path;
  struct s_node *next;
}	t_nd;

typedef struct s_tunl
{
  t_nd		*exit;
  char		trafic;
  struct s_tunl	*next;
}	t_tn;

/*
** Définir l'emplacement de la fourmi selon le node ou la fourmi ?
*/

typedef struct s_ant
{
  int		number;
  t_nd		*node;
  struct s_ant	*next;
}	t_ant;

#endif
