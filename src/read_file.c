/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:55:32 by yholub            #+#    #+#             */
/*   Updated: 2018/06/22 11:09:44 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		err(void)
{
	ft_putendl("Not correct file");
	exit(1);
}

char	*get_file_2(char *res, char *buff, char *temp)
{
	int i;

	i = 0;
	while (get_next_line(0, &buff) && i++ != 9000)
	{
		temp = ft_strdup(res);
		ft_strdel(&res);
		res = ft_strjoin(temp, buff);
		ft_strdel(&temp);
		temp = ft_strdup(res);
		ft_strdel(&res);
		res = ft_strjoin(temp, "\n");
		ft_strdel(&temp);
		ft_strdel(&buff);
	}
	if (i > 9000)
	{
		ft_strdel(&res);
		ft_printf("Too large file\n");
		exit(0);
	}
	return (res);
}

char	*get_file(void)
{
	char *buff;
	char *temp;
	char *res;

	if ((get_next_line(0, &buff) < 1))
		err();
	res = ft_strdup(buff);
	temp = ft_strdup(res);
	ft_strdel(&res);
	res = ft_strjoin(temp, "\n");
	ft_strdel(&temp);
	ft_strdel(&buff);
	res = get_file_2(res, buff, temp);
	return (res);
}

int		not_empty(char *data)
{
	int i;

	i = 0;
	while (data[i])
	{
		if (!ft_iswhitespace(data[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*read_file(void)
{
	char	*res;

	res = get_file();
	if (!not_empty(res))
	{
		ft_printf("Only whitespaces!\n");
		exit(1);
	}
	if (check_valid(res))
		return (res);
	else
		return (NULL);
}
