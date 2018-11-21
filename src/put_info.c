/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:31:46 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:09:36 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	put_int_stu(t_lem *stu, char *des, int index)
{
	int i;

	i = 0;
	while (i < stu->c_nodes)
	{
		if (!ft_strcmp(stu->nodes[i].name, des))
		{
			stu->nodes[index].links[i] = 1;
			stu->nodes[i].links[index] = 1;
		}
		i++;
	}
}

void	free_mass(int **mas, int lim)
{
	int i;

	i = 0;
	while (i < lim)
	{
		free(mas[i]);
		mas[i] = NULL;
		i++;
	}
	free(mas);
}

char	*add_way(char *res, char *way)
{
	char *buff;

	buff = ft_strdup(res);
	ft_strdel(&res);
	res = ft_strjoin(buff, "\n");
	ft_strdel(&buff);
	buff = ft_strdup(res);
	ft_strdel(&res);
	res = ft_strjoin(buff, way);
	ft_strdel(&buff);
	return (res);
}

int		find_last(char **mass)
{
	int y;

	y = 0;
	while (mass[y + 1] && mass[y + 1] != NULL)
		y++;
	return (y);
}

int		is_valid_way(char *buff, t_lem *stu)
{
	char	**temp;
	int		start;
	int		end;
	int		i;
	int		res;

	res = 0;
	start = find_start(stu);
	end = find_end(stu);
	temp = ft_strsplit(buff, '-');
	if (!ft_strcmp(temp[0], stu->nodes[start].name))
		if (!ft_strcmp(temp[find_last(temp)], stu->nodes[end].name))
			res = 1;
	i = 0;
	while (temp[i])
	{
		ft_strdel(&temp[i]);
		i++;
	}
	free(temp);
	return (res);
}
