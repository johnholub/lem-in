/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:17:30 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:08:52 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			get_nodes(char *data, int c_line)
{
	int		i;
	int		res;
	char	*buf;

	i = 0;
	res = 0;
	while (i < c_line)
	{
		buf = get_one_line(data, i);
		if (is_room(buf))
			res++;
		ft_strdel(&buf);
		i++;
	}
	return (res);
}

int			get_ants(char *data, int c_line)
{
	int		res;
	char	*buff;
	int		i;

	i = 0;
	while (i < c_line)
	{
		buff = get_one_line(data, i);
		if (buff[0] != '#')
		{
			res = ft_atoi(buff);
			ft_strdel(&buff);
			return (res);
		}
		ft_strdel(&buff);
		i++;
	}
	return (0);
}

int			*init_links(int count)
{
	int	*res;
	int i;

	i = 0;
	res = (int*)malloc(sizeof(int) * count + 1);
	while (i < count)
	{
		res[i] = 0;
		i++;
	}
	res[i] = '\0';
	return (res);
}

t_lem		*init_stu(char *data)
{
	t_lem	*res;
	int		i;

	i = 0;
	res = (t_lem*)malloc(sizeof(t_lem));
	res->c_line = count_line(data);
	res->c_ants = get_ants(data, res->c_line);
	res->c_nodes = get_nodes(data, res->c_line);
	res->nodes = (t_nodes*)malloc(sizeof(t_nodes) * res->c_nodes);
	while (i < res->c_nodes)
	{
		res->nodes[i].name = NULL;
		res->nodes[i].end = 0;
		res->nodes[i].start = 0;
		res->nodes[i].links = init_links(res->c_nodes);
		i++;
	}
	return (res);
}

t_lem		*get_info(char *data)
{
	t_lem	*res;

	res = init_stu(data);
	node_info(data, res);
	if (res->c_ants <= 0)
		ex_stu(res, data, 2);
	return (res);
}
