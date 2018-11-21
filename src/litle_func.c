/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litle_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:11:41 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:09:10 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_line(char *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data[i])
	{
		if (data[i] == '\n')
		{
			j++;
			if (data[i + 1] == '\n')
				return (j);
		}
		i++;
	}
	if (data[i - 1] != '\n')
		return (j + 1);
	return (j);
}

int		skip_line(char *str, int k)
{
	int res;
	int j;

	res = 0;
	j = 0;
	while (str[res] && k > j)
	{
		if (str[res] == '\n')
			j++;
		res++;
	}
	return (res);
}

size_t	size_line(char *data, int j)
{
	size_t res;

	res = 0;
	while (data[j] && data[j] != '\n')
	{
		res++;
		j++;
	}
	return (res);
}

char	*get_one_line(char *data, int i)
{
	int		j;
	int		k;
	char	*res;

	j = skip_line(data, i);
	k = 0;
	res = ft_strnew(size_line(data, j));
	while (data[j] && data[j] != '\n')
	{
		res[k] = data[j];
		k++;
		j++;
	}
	res[k] = '\0';
	return (res);
}

void	del_field(int y, t_lem *stu)
{
	int i;

	i = 0;
	while (i < stu->c_nodes)
	{
		if (stu->nodes[y].links[i] != 0)
			stu->nodes[y].links[i] = 0;
		i++;
	}
	i = 0;
	while (i < stu->c_nodes)
	{
		if (stu->nodes[i].links[y] != 0)
			stu->nodes[i].links[y] = 0;
		i++;
	}
}
