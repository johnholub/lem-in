/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:18:56 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:07:53 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		skip_to_coord(char *data, int i)
{
	while (data[i] && data[i] != ' ')
		i++;
	while (data[i] && data[i] == ' ')
		i++;
	return (i);
}

int		is_room(char *data)
{
	int	name;
	int coor;
	int i;

	i = 0;
	name = 0;
	coor = 0;
	if (data[0] == 'L' || ft_iswhitespace(data[0]))
		return (0);
	i = skip_to_coord(data, i);
	name++;
	while ((ft_isdigit(data[i]) || data[i] == ' ') &&
			i < (int)ft_strlen(data))
	{
		if (ft_isdigit(data[i]))
		{
			coor++;
			while (ft_isdigit(data[i]) && i < (int)ft_strlen(data))
				i++;
		}
		i++;
	}
	if (name == 1 && coor == 2)
		return (1);
	return (0);
}

void	break_links(t_lem *stu)
{
	int x;
	int y;

	y = 0;
	while (y < stu->c_nodes)
	{
		x = 0;
		while (x < stu->c_nodes)
		{
			stu->nodes[y].links[x] = 0;
			x++;
		}
		y++;
	}
}

int		is_link(char *data)
{
	int def;
	int i;

	i = 0;
	def = 0;
	while (i < (int)ft_strlen(data) && !ft_iswhitespace(data[i]))
	{
		if (data[i] == '-')
			def++;
		i++;
	}
	if (def == 1 && (int)ft_strlen(data) == i)
		return (1);
	return (0);
}
