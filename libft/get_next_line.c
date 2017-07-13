/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:38:16 by ltesson           #+#    #+#             */
/*   Updated: 2016/01/06 18:50:42 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void	ft_lstdelchar(void *content, size_t size)
{
	ft_bzero(content, size);
	if (content)
		free(content);
}

static void	ft_cpyline(int i, t_list *list, char **line)
{
	*line = ft_strnew(i);
	while (i)
	{
		(*line)[i - 1] = *((char*)list->content);
		list = list->next;
		i--;
	}
}

int			get_next_line(int const fd, char **line)
{
	char	c;
	t_list	*list;
	int		i;
	int		r;

	list = ft_lstnew(NULL, 0);
	i = 0;
	r = read(fd, &c, 1);
	while (r > 0 && c != '\n')
	{
		ft_lstadd(&list, ft_lstnew(&c, sizeof(char)));
		i++;
		r = read(fd, &c, 1);
	}
	if (r == -1 || list == NULL)
		return (-1);
	ft_cpyline(i, list, line);
	ft_lstdel(&list, ft_lstdelchar);
	return (r);
}
