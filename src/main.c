/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:15:29 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:09:21 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_mas_char(char **m)
{
	int i;

	i = 0;
	while (m[i] != NULL)
	{
		ft_strdel(&m[i]);
		i++;
	}
	free(m);
}

void	final_prep(char *res)
{
	if (res[ft_strlen(res) - 1] == '\n' && res[ft_strlen(res) - 2] == '\n')
		res[ft_strlen(res) - 1] = '\0';
}

void	find_solution(char *data, t_lem *stu)
{
	char *ways;
	char **m_ways;
	char **traf;
	char *res;

	ways = find_ways(stu);
	if (ways == NULL)
	{
		ft_strdel(&ways);
		ex_stu(stu, data, 1);
	}
	m_ways = ft_strsplit(ways, '\n');
	traf = create_trafick(m_ways, stu);
	stu->c_ways = find_last(m_ways) + 1;
	res = build_traf(traf, stu);
	final_prep(res);
	ft_printf("FILE:\n%s\nSOLUTION:\n%s", data, res);
	ft_strdel(&ways);
	free_mas_char(m_ways);
	free_mas_char(traf);
	ft_strdel(&res);
}

int		main(int argc, char **argv)
{
	char	*data;
	t_lem	*res;

	if (argc > 1)
	{
		data = ft_strdup(argv[1]);
		ft_printf("Usage: ./lem_in < (file)\n");
		ft_strdel(&data);
		exit(0);
	}
	data = read_file();
	res = get_info(data);
	find_solution(data, res);
	return (0);
}
