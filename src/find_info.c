/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:37:42 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:08:20 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		find_start(t_lem *stu)
{
	int i;

	i = 0;
	while (i < stu->c_nodes)
	{
		if (stu->nodes[i].start == 1)
			return (i);
		i++;
	}
	return (0);
}

int		find_end(t_lem *stu)
{
	int i;

	i = 0;
	while (i < stu->c_nodes)
	{
		if (stu->nodes[i].end == 1)
			return (i);
		i++;
	}
	return (0);
}

int		is_links_ex(t_lem *stu)
{
	int y;
	int x;

	y = find_end(stu);
	x = 0;
	while (x < stu->c_nodes)
	{
		if (stu->nodes[y].links[x] == 1)
			return (1);
		x++;
	}
	return (0);
}

int		can_put(int **mass, int i)
{
	int y;
	int x;

	y = 0;
	while (mass[y])
	{
		x = 0;
		while (mass[y][x])
		{
			if (mass[y][x] == i - 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
