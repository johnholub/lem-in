/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:27:29 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:08:08 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	error_message(int i)
{
	if (i == 1)
		ft_printf("ERROR\n");
	else if (i == 2)
		ft_printf("ERROR\n");
	else if (i == 3)
		ft_printf("ERROR\n");
	else if (i == 4)
		ft_printf("ERROR\n");
	else if (i == 5)
		ft_printf("ERROR\n");
	else if (i == 6)
		ft_printf("ERROR\n");
	else if (i == 7)
		ft_printf("ERROR\n");
	else if (i == 8)
		ft_printf("ERROR\n");
}

void	ex_err(char *data, char *buf, int i)
{
	if (buf)
		ft_strdel(&buf);
	if (data)
		ft_strdel(&data);
	error_message(i);
	exit(1);
}

void	free_stu(t_lem *stu)
{
	int i;

	i = 0;
	if (stu)
	{
		while (i < stu->c_nodes)
		{
			if (stu->nodes[i].name)
				ft_strdel(&stu->nodes[i].name);
			if (stu->nodes[i].links)
			{
				free(stu->nodes[i].links);
				stu->nodes[i].links = NULL;
			}
			i++;
		}
		free(stu->nodes);
		stu->nodes = NULL;
		free(stu);
	}
}

void	ex_stu(t_lem *stu, char *buf, int i)
{
	if (stu)
		free_stu(stu);
	if (buf)
		ft_strdel(&buf);
	error_message(i);
	exit(1);
}
