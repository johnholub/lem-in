/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:26:26 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:08:27 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			**init_temp(int size)
{
	int **res;
	int x;
	int y;

	y = 0;
	res = (int **)malloc(sizeof(int *) * size + 1);
	while (y < size)
	{
		x = 0;
		res[y] = (int *)malloc(sizeof(int) * size + 1);
		while (x < size)
		{
			res[y][x] = INT_MAX;
			x++;
		}
		res[y][x] = '\0';
		y++;
	}
	res[y] = 0;
	return (res);
}

void		fill_string(int *des, int *src, int st, int lim)
{
	int x;

	x = 0;
	while (x < lim)
	{
		if (src[x] == 1 && des[x] > st)
			des[x] = st;
		else if (src[x] == 0 && des[x] == INT_MAX)
			des[x] = -1;
		x++;
	}
}

void		fill_steps(int **mas, t_lem *stu)
{
	int		st;
	int		i;
	int		x;
	int		j;

	x = 1;
	st = find_start(stu);
	fill_string(mas[st], stu->nodes[st].links, x, stu->c_nodes);
	while (can_put(mas, x) || x == 1)
	{
		i = 0;
		while (mas[i])
		{
			j = 0;
			while (mas[i][j])
			{
				if (mas[i][j] == x)
					fill_string(mas[j],
								stu->nodes[j].links, x + 1, stu->c_nodes);
				j++;
			}
			i++;
		}
		x++;
	}
}

char		*find_way(t_lem *stu)
{
	int		**temp;
	char	*res;

	temp = init_temp(stu->c_nodes);
	fill_steps(temp, stu);
	res = from_end(temp, stu);
	free_mass(temp, stu->c_nodes);
	return (res);
}

char		*find_ways(t_lem *stu)
{
	char	*res;
	char	*buf;
	int		first;

	first = 0;
	res = NULL;
	while (is_links_ex(stu))
	{
		buf = find_way(stu);
		if (first == 0 && is_valid_way(buf, stu))
		{
			first++;
			res = ft_strdup(buf);
		}
		else if (is_valid_way(buf, stu))
			res = add_way(res, buf);
		rm_link(buf, stu);
		ft_strdel(&buf);
	}
	return (res);
}
