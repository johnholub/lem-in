/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:31:38 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:07:35 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_count(char *data)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(data))
	{
		if (!ft_isdigit(data[i]))
			return (0);
		i++;
	}
	return (1);
}

int		count_order(char *data, int c_line)
{
	int		i;
	char	*buf;

	i = 0;
	buf = get_one_line(data, i);
	while (i < c_line)
	{
		i++;
		if (is_count(buf))
		{
			ft_strdel(&buf);
			return (i);
		}
		else if (buf[0] == '#')
		{
			ft_strdel(&buf);
			buf = get_one_line(data, i);
		}
		else
			ex_err(data, buf, 1);
	}
	ex_err(data, buf, 1);
	return (0);
}

int		room_order(char *data, int i, int c_line)
{
	char *buf;

	buf = NULL;
	while (i < c_line)
	{
		buf = get_one_line(data, i);
		if (buf[0] != '#' && !is_room(buf))
		{
			if (is_link(buf))
			{
				ft_strdel(&buf);
				return (i);
			}
			else
				ex_err(data, buf, 2);
		}
		ft_strdel(&buf);
		i++;
	}
	ex_err(data, buf, 3);
	return (0);
}

int		link_order(char *data, int i, int c_line)
{
	char *buf;

	while (i < c_line)
	{
		buf = get_one_line(data, i);
		if (buf[0] != '#' && !is_link(buf))
			ex_err(data, buf, 4);
		ft_strdel(&buf);
		i++;
	}
	return (i);
}

int		check_order(char *data)
{
	int		i;
	int		c_line;

	c_line = count_line(data);
	i = count_order(data, c_line);
	i = room_order(data, i, c_line);
	i = link_order(data, i, c_line);
	if (i == c_line && check_comand(data, c_line))
		return (1);
	return (0);
}
