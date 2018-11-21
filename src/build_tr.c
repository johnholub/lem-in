/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:20:47 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:07:15 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		find_farest(char **mass)
{
	int x;
	int y;
	int buf;
	int res;

	y = 0;
	res = 0;
	while (mass[y])
	{
		x = 0;
		buf = 0;
		while (mass[y][x])
		{
			if (mass[y][x] == ' ')
				buf++;
			x++;
		}
		if (res < buf)
			res = buf;
		y++;
	}
	return (res);
}

char	*joinw_space(char *res, char *ned)
{
	if (ned != NULL)
	{
		if (res == NULL)
		{
			res = ft_strdup(ned);
			return (res);
		}
		if (res[ft_strlen(res) - 1] != '\n')
			res = paste_one(res, " ");
		res = paste_one(res, ned);
	}
	return (res);
}

char	*get_room(char *des, int y)
{
	char	*res;
	char	**temp;
	int		lim;
	int		i;

	i = 0;
	temp = ft_strsplit(des, ' ');
	lim = lim_of(des);
	if (lim < y)
		return (NULL);
	res = ft_strdup(temp[y]);
	while (temp[i])
	{
		ft_strdel(&temp[i]);
		i++;
	}
	free(temp);
	return (res);
}

char	*give_way(char *res, char **ways, int x, t_lem *stu)
{
	int		y;
	char	*buff;
	int		add;
	int		steps;

	add = 0;
	if (x > (find_farest(ways) - 1))
	{
		add = x - (find_farest(ways) - 1);
		x = (find_farest(ways) - 1);
	}
	y = -1 + (add * stu->c_ways);
	while (x >= 0)
	{
		steps = -1;
		while (++steps < stu->c_ways && ++y < stu->c_ants)
		{
			buff = get_room(ways[y], x);
			res = joinw_space(res, buff);
			ft_strdel(&buff);
		}
		x--;
	}
	return (res);
}

char	*build_traf(char **ways, t_lem *stu)
{
	char	*res;
	int		i;
	int		x;
	int		lim;

	x = 0;
	i = 0;
	res = NULL;
	lim = (stu->c_ants / stu->c_ways) + (find_farest(ways));
	while (i < lim)
	{
		res = give_way(res, ways, x, stu);
		res = paste_one(res, "\n");
		x++;
		i++;
	}
	return (res);
}
