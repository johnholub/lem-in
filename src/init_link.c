/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:13:48 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:09:02 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		index_sep(char *buf, char c)
{
	int		res;

	res = 0;
	while (res < (int)ft_strlen(buf) && buf[res] != c)
		res++;
	return (res);
}

char	*before_sep(char *buf, char c)
{
	char	*res;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = index_sep(buf, c);
	res = ft_strnew((size_t)size);
	while (i < size)
	{
		res[j] = buf[i];
		j++;
		i++;
	}
	return (res);
}

char	*after_sep(char *buf, char c)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = index_sep(buf, c) + 1;
	res = ft_strnew(ft_strlen(buf) - (size_t)size);
	while (size < (int)ft_strlen(buf))
	{
		res[i] = buf[size];
		i++;
		size++;
	}
	return (res);
}

void	rm_st_en(t_lem *stu)
{
	int start;
	int end;

	start = find_start(stu);
	end = find_end(stu);
	stu->nodes[start].links[end] = 0;
	stu->nodes[end].links[start] = 0;
}

int		st_en(char *s1, char *s2, t_lem *stu)
{
	int start;
	int end;

	start = find_start(stu);
	end = find_end(stu);
	if (!ft_strcmp(s1, stu->nodes[start].name) ||
			!ft_strcmp(s1, stu->nodes[end].name))
		if (!ft_strcmp(s2, stu->nodes[start].name) ||
				!ft_strcmp(s2, stu->nodes[end].name))
			return (1);
	return (0);
}
