/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:44:19 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:07:28 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		comand_count(char *data, int c_line)
{
	int		i;
	int		start;
	int		end;
	char	*buf;

	i = 0;
	start = 0;
	end = 0;
	buf = NULL;
	while (i < c_line)
	{
		buf = get_one_line(data, i);
		if (!ft_strcmp("##start", buf))
			start++;
		if (!ft_strcmp("##end", buf))
			end++;
		ft_strdel(&buf);
		i++;
	}
	if (start == 1 && end == 1)
		return (1);
	ex_err(data, buf, 5);
	return (0);
}

int		is_start_com(char *data, int i, int c_line)
{
	char *buff;

	i++;
	while (i < c_line)
	{
		buff = get_one_line(data, i);
		if (is_room(buff))
		{
			ft_strdel(&buff);
			return (i);
		}
		else if (buff[0] == '#' && (ft_strcmp(buff, "##start") ||
				ft_strcmp(buff, "##end")))
		{
			i++;
			ft_strdel(&buff);
		}
		else
			ex_err(data, buff, 6);
	}
	ex_err(data, buff, 6);
	return (0);
}

int		is_end_com(char *data, int i, int c_line)
{
	char *buff;

	i++;
	while (i < c_line)
	{
		buff = get_one_line(data, i);
		if (is_room(buff))
		{
			ft_strdel(&buff);
			return (i);
		}
		else if (buff[0] == '#' && (ft_strcmp(buff, "##start") ||
				ft_strcmp(buff, "##end")))
		{
			i++;
			ft_strdel(&buff);
		}
		else
			ex_err(data, buff, 7);
	}
	ex_err(data, buff, 7);
	return (0);
}

int		comand_replacment(char *data, int c_line)
{
	int		i;
	char	*buf;

	i = 0;
	while (i < c_line)
	{
		buf = get_one_line(data, i);
		if (!ft_strcmp("##start", buf))
			i = is_start_com(data, i, c_line);
		if (!ft_strcmp("##end", buf))
			i = is_end_com(data, i, c_line);
		ft_strdel(&buf);
		i++;
	}
	return (1);
}

int		check_comand(char *data, int c_line)
{
	if (comand_count(data, c_line))
		if (comand_replacment(data, c_line))
			return (1);
	return (0);
}
