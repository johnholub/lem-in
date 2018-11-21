/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:27:27 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:08:36 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		exept_nl(int i, int r, char *data)
{
	while (data[i] != '\0')
	{
		if (!ft_iswhitespace(data[i]))
		{
			ft_printf("%s%i%s\n", "line ", r, " is empty...");
			ft_strdel(&data);
			exit(1);
		}
		i++;
	}
	return (1);
}

int		no_empty_lines(char *data)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (data[i])
	{
		if (data[i] == '\n')
		{
			r++;
			if (data[i - 1] == '\n')
				if (!exept_nl(i, r, data))
					return (0);
		}
		i++;
	}
	return (1);
}

int		check_valid(char *data)
{
	if (!no_empty_lines(data))
	{
		ft_printf("Empty line\n");
		ft_strdel(&data);
		exit(1);
	}
	if (check_order(data))
		return (1);
	return (0);
}
