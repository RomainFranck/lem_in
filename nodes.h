/*
** nodes.h for lem_in in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 11:09:02 2014 Romain Franck
** Last update Wed Apr 23 17:31:52 2014 Galleg_a
*/

#ifndef NODES_H_
# define NODES_H_

typedef struct	s_node
{
  struct s_node	*prev;
  char		*name;
  int		weight;
  char		full;
<<<<<<< HEAD
  char		**link;
  /*struct s_node	*links;*/
=======
  struct s_node	**links;
>>>>>>> 490ea63400d3cdee162eb2d3e04ccc7a7d7ad9bb
  struct s_node	*next;
} t_nd;

typedef struct	s_farm_sen
{
  t_nd		*start;
  t_nd		*exit;
  t_nd		*first;
  t_nd		*last;
  unsigned	size;
  int		ants;
} t_frm;

typedef struct	s_ant
{
  int		number;
  t_nd		*node;
  struct s_ant	*next;
} t_ant;

#endif
