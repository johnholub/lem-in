/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:13:44 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:08:44 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		next_room(int *mas, int lim)
{
	int i;
	int res;
	int val;

	i = 0;
	res = -1;
	val = INT_MAX;
	while (i < lim)
	{
		if (mas[i] < val && mas[i] != -1)
		{
			val = mas[i];
			res = i;
		}
		i++;
	}
	return (res);
}

char	*join_sol(char *res, char *room)
{
	char *buff;

	buff = ft_strjoin("-", res);
	ft_strdel(&res);
	res = ft_strjoin(room, buff);
	ft_strdel(&buff);
	return (res);
}

char	*from_end(int **mass, t_lem *stu)
{
	char	*res;
	int		i;
	int		prev;
	int		ind;

	ind = 0;
	i = find_end(stu);
	res = ft_strdup(stu->nodes[i].name);
	while (stu->nodes[i].start == 0)
	{
		prev = i;
		i = next_room(mass[i], stu->c_nodes);
		if (i == -1 || ind > 10000)
		{
			break_links(stu);
			return (res);
		}
		mass[i][prev] = -1;
		res = join_sol(res, stu->nodes[i].name);
		ind++;
	}
	return (res);
}

int		find_room(char *temp, t_lem *stu)
{
	int		res;

	res = 0;
	while (res < stu->c_nodes)
	{
		if (!ft_strcmp(stu->nodes[res].name, temp))
			return (res);
		res++;
	}
	return (0);
}

void	rm_link(char *buf, t_lem *stu)
{
	char	**rs;
	int		i;
	int		y;
	int		last;

	i = 1;
	rs = ft_strsplit(buf, '-');
	last = find_last(rs);
	if (last == 1 && st_en(rs[0], rs[1], stu))
		rm_st_en(stu);
	while (i < last)
	{
		y = find_room(rs[i], stu);
		del_field(y, stu);
		i++;
	}
	i = 0;
	while (rs[i])
	{
		ft_strdel(&rs[i]);
		i++;
	}
	free(rs);
}
