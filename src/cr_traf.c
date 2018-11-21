/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_traf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:13:33 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:08:01 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		*paste_one(char *s1, char *s2)
{
	char *buf;

	buf = ft_strdup(s1);
	ft_strdel(&s1);
	s1 = ft_strjoin(buf, s2);
	ft_strdel(&buf);
	return (s1);
}

int			lim_of(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			res++;
		i++;
	}
	return (res - 1);
}

char		*tr_forant(char *way, char *ant_n)
{
	char	**rooms;
	int		r_id;
	char	*res;
	int		i;

	i = -1;
	r_id = 1;
	rooms = ft_strsplit(way, '-');
	res = ft_strjoin("L", ant_n);
	while (rooms[r_id] && rooms[r_id] != NULL)
	{
		res = paste_one(res, "-");
		res = paste_one(res, rooms[r_id]);
		res = paste_one(res, " ");
		if (rooms[r_id + 1] != NULL)
		{
			res = paste_one(res, "L");
			res = paste_one(res, ant_n);
		}
		r_id++;
	}
	while (++i < r_id)
		free(rooms[i]);
	free(rooms);
	return (res);
}

char		**create_trafick(char **m_ways, t_lem *stu)
{
	int		c_ways;
	int		ant;
	int		way;
	char	*c_ants;
	char	**res;

	ant = 0;
	way = 0;
	c_ways = find_last(m_ways) + 1;
	res = (char **)malloc(sizeof(char *) * stu->c_ants + 1);
	while (ant < stu->c_ants)
	{
		if (way >= c_ways)
			way = 0;
		c_ants = ft_itoa(ant + 1);
		res[ant] = tr_forant(m_ways[way], c_ants);
		ft_strdel(&c_ants);
		ant++;
		way++;
	}
	res[ant] = 0;
	return (res);
}
