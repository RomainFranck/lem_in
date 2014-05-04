#ifndef LEMIN_H_
# define LEMIN_H_

#include "nodes.h"

/*-------------[ants.c]------------*/
void	smashTheAnts(t_ant *queen);
t_ant	*antCreate(t_ant *queen, t_nd *position, int i);
t_ant	*releaseTheAnts(int nb, t_nd *position);
/*---------------------------------*/

/*-------------[backtrack.c]------------*/
void	init(t_frm *sen);
void	path(t_pn *list, t_nd *room);
void	noway(t_pn *list);
void	backtrack2(t_frm *sen, t_nd *room, t_pn *list);
void	backtrack(t_frm *sen, t_nd *room, int i);
void	cleaningWoman(t_frm *sen);
int	move(t_ant *ant);
int	soil(t_ant *ant);
int	antAction(t_ant *ant, int (*Action)(t_ant*));
/*--------------------------------------*/

/*-------------[create_tree.c]------------*/
int    	count_nodes(char *name, t_sln *links);
t_nd		*find_node(t_frm *farm, char *name);
int	fill_node_links(int size, t_nd *r, t_sln *links, t_frm *farm);
void	del_link_in_full(t_sln *links, t_lnk *link);
t_lnk	*r_maillon(t_lnk *link, t_sln *links, int *next);
void	del_doublons(t_sln *links);
int	is_useless(char *link);
void	del_useless(t_sln *links);
int		init_tree(t_frm *farm, t_sln *links);
/*----------------------------------------*/

/*-------------[epur_tree.c]------------*/
int	epur_tree(t_frm *farm);
/*--------------------------------------*/

/*-------------[getnbr.c]------------*/
int	is_alphaz(char c);
int	my_getnbr_aux(int nbr, char *str, int minus);
int	my_getnbr(char *str);
/*-----------------------------------*/

/*-------------[getnextline.c]------------*/
char	*my_strcpy(char *dest, char *src);
char	*my_realloc(char *buff);
char	*norme_get_next(int *i, char *str, int j);
char		*getnextline(int fd);
/*----------------------------------------*/

/*-------------[link_everything.c]------------*/
int	check_already_exist(t_nd *node, t_lnk *link);
int	count_other_nodes(char *name, t_nd *node, t_sln *links);
t_nd	**fill_new_links(t_nd *node, t_sln *links, t_nd **new_links, t_frm *farm);
int		link_everything(t_frm *farm, t_sln *links);
/*--------------------------------------------*/

/*-------------[main.c]------------*/
int	create_tree(t_frm *farm, t_sln *links);
int	is_alphanum(char c);
int	valid_link_input(char *line);
int	valid_node_input(char *line);
void	manage_link(char *line, t_sln *links, int *kill);
void	add_valid_node(t_frm *farm, char *line, int *kill, int type);
void	comment(t_frm *farm, char *line, int *kill);
void	manage_rooms(char *line, int *kill, t_frm *farm);
int	create_node_list(t_frm *farm, t_sln *links);
int	main();
/*---------------------------------*/

/*-------------[my_strcpy.c]------------*/
char	*my_strcpy(char *dest, char *src);
char	*my_strcpy2(char *head, char *str, int i);
/*--------------------------------------*/

/*-------------[nodes.c]------------*/
void	get_links(char *line, t_lnk *maillon);
void	in_empty_link_list(t_sln *links, t_lnk *maillon, char *line);
void	in_link_list(t_sln *links, t_lnk *maillon, char *line);
t_lnk	*add_link_to_list(t_sln *links, char *line);
t_nd	*add_node_to_list(t_frm *farm, int type, char *line);
char	*get_name(char *line);
void	put_in_empty_node_list(t_frm *farm, t_nd *maillon, char *line);
void	put_in_node_list(t_frm *farm, t_nd *maillon, char *line);
t_nd	*nd_find(t_nd *f, char *name);
int	pth_find(t_pn *list, t_nd *room);
/*----------------------------------*/

/*-------------[str.c]------------*/
int		my_strlen_no_troll(const char *s_ptr);
char	*my_strdup_no_troll(char *src);
int	my_strcmp_no_troll(char *s1, char *s2);
int	my_strncmp(const char *s1, const char *s2, int n);
int	my_strcmp(char *a, char *b);
int	my_strlen(char *s, int i);
char	*my_strdup(char *s, int i);
/*--------------------------------*/

#endif
