/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:51:57 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:09:29 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	apply_link(t_lem *stu, char *buf)
{
	int		i;
	char	*first;
	char	*second;

	i = 0;
	first = before_sep(buf, '-');
	second = after_sep(buf, '-');
	if (!ft_strcmp(first, second))
		ex_stu(stu, buf, 8);
	while (i < stu->c_nodes)
	{
		if (!ft_strcmp(stu->nodes[i].name, first))
			put_int_stu(stu, second, i);
		if (!ft_strcmp(stu->nodes[i].name, second))
			put_int_stu(stu, first, i);
		i++;
	}
	ft_strdel(&first);
	ft_strdel(&second);
}

void	set_links(t_lem *stu, char *data)
{
	int		i;
	char	*buf;

	i = 0;
	while (i < stu->c_line)
	{
		buf = get_one_line(data, i);
		if (is_link(buf))
			apply_link(stu, buf);
		ft_strdel(&buf);
		i++;
	}
}

void	set_command(int i, t_lem *stu, char *buf)
{
	if (!ft_strcmp("##start", buf))
		stu->nodes[i].start = 1;
	if (!ft_strcmp("##end", buf))
		stu->nodes[i].end = 1;
}

void	set_nodenames(t_lem *stu, char *data)
{
	int		i;
	int		j;
	int		k;
	char	*buf;

	i = 0;
	k = 0;
	while (i < stu->c_line)
	{
		buf = get_one_line(data, i);
		if (!ft_strcmp("##start", buf) || !ft_strcmp("##end", buf))
			set_command(k, stu, buf);
		if (is_room(buf))
		{
			j = 0;
			while (!ft_iswhitespace(buf[j]))
				j++;
			buf = ft_realloc(buf, (size_t)j);
			stu->nodes[k].name = ft_strdup(buf);
			k++;
		}
		ft_strdel(&buf);
		i++;
	}
}

void	node_info(char *data, t_lem *stu)
{
	set_nodenames(stu, data);
	set_links(stu, data);
}
