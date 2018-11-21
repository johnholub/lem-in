/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:15:40 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:10:40 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../ft_printf/ft_printf/ft_printf.h"

typedef struct	s_nodes
{
	char		*name;
	int			start;
	int			end;
	int			*links;
}				t_nodes;

typedef struct	s_lem
{
	int			c_line;
	int			c_ants;
	int			c_nodes;
	int			c_ways;
	t_nodes		*nodes;
}				t_lem;

char			*read_file(void);
int				check_valid(char *data);
int				check_order(char *data);
char			*get_one_line(char *data, int i);
int				count_line(char *data);
int				is_room(char *data);
int				is_link(char *data);
int				check_comand(char *data, int c_line);
void			ex_err(char *data, char *buf, int i);
t_lem			*get_info(char *data);
void			node_info(char *data, t_lem *stu);
char			*before_sep(char *buf, char c);
char			*after_sep(char *buf, char c);
void			ex_stu(t_lem *stu, char *buf, int i);
void			free_stu(t_lem *stu);
void			put_int_stu(t_lem *stu, char *des, int i);
char			*find_ways(t_lem *stu);
int				find_start(t_lem *stu);
int				find_end(t_lem *stu);
int				can_put(int **mass, int i);
char			*from_end(int **mass, t_lem *stu);
void			del_field(int y, t_lem *stu);
void			rm_link(char *buf, t_lem *stu);
void			free_mass(int **mas, int lim);
int				is_valid_way(char *buff, t_lem *stu);
char			*add_way(char *res, char *way);
int				is_links_ex(t_lem *stu);
int				find_last(char **mass);
void			rm_st_en(t_lem *stu);
int				st_en(char *s1, char *s2, t_lem *stu);
char			**create_trafick(char **m_ways, t_lem *stu);
char			*build_traf(char **ways, t_lem *stu);
char			*paste_one(char *s1, char *s2);
void			break_links(t_lem *stu);
int				lim_of(char *str);

#endif
