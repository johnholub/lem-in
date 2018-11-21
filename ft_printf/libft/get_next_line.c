/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:54:05 by yholub            #+#    #+#             */
/*   Updated: 2017/12/11 11:54:19 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*search_file(t_list **file, int fd)
{
	t_list			*temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	temp = *file;
	return (temp);
}

char	*copy_from(char *str2, int i)
{
	int		k;
	int		len;
	char	*str;

	k = 0;
	if (!str2)
		len = 0;
	len = ft_strlen(str2) - i;
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	while (str2[i] != '\0')
	{
		str[k] = str2[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}

int		is_line(t_list *lst, char **line, int ch)
{
	int		i;
	char	*temp;

	i = -1;
	if (lst->content == NULL)
		return (0);
	if (ft_strchr(lst->content, '\n'))
		while (&lst->content[++i])
			if (((char*)lst->content)[i] == '\n')
			{
				*line = ft_strnew(i);
				ft_strncpy(*line, lst->content, i);
				temp = copy_from(lst->content, i + 1);
				lst->content = ft_realloc(lst->content, (ft_strlen(temp) + 1));
				ft_strcpy(lst->content, temp);
				free(temp);
				return (1);
			}
	if (!(ft_strchr(lst->content, '\n')) && !ch && ft_strlen(lst->content) != 0)
	{
		*line = copy_from(lst->content, 0);
		lst->content = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static t_list	*head;
	t_list			*tmp;
	int				i;
	int				ch;

	i = 0;
	if (line == NULL || fd < 0 || BUFF_SIZE == 0 || read(fd, buffer, 0) < 0)
		return (-1);
	tmp = search_file(&head, fd);
	while ((ch = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ch++] = '\0';
		i = i + BUFF_SIZE;
		tmp->content = ft_realloc(tmp->content,
			(i + (int)ft_strlen(tmp->content)) + 1);
		ft_strcat(tmp->content, buffer);
		if (is_line(tmp, line, ch))
			return (1);
	}
	if (!(ch = read(fd, buffer, BUFF_SIZE)) && (is_line(tmp, line, ch)))
		return (1);
	return (0);
}
