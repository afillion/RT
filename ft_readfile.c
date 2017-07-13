/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:47:41 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/15 18:38:52 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"
#include <fcntl.h>

void	ft_readitem(t_scene *s, int fd, char *line, int *i)
{
	if (ft_strcasecmp("spot", line) == 0)
		ft_readspot(s, fd, line, i);
	else if (ft_strcasecmp("sphere", line) == 0)
		ft_readsphere(s, fd, line, i);
	else if (ft_strcasecmp("plan", line) == 0)
		ft_readplan(s, fd, line, i);
	else if (ft_strcasecmp("cylindre", line) == 0)
		ft_readcylindre(s, fd, line, i);
	else if (ft_strcasecmp("cone", line) == 0)
		ft_readcone(s, fd, line, i);
	else if (ft_strcasecmp("camera", line) == 0)
		ft_readcamera(s, fd, line, i);
}

void	ft_readfile(t_scene *s, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		s->error = 3;
		return ;
	}
	i = get_next_line(fd, &line);
	s->name = ft_strdup(line);
	if (s->name == NULL)
		s->error = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		ft_readitem(s, fd, line, &i);
	}
}
