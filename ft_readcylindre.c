/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcylindre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:47:21 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/15 17:31:04 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_cylindredata(t_cylindre *cylindre, char *line)
{
	char	**split;

	split = ft_strsplit(line, ':');
	if (split == NULL)
		return ;
	if (split[1] != NULL)
	{
		if (ft_strcasecmp("x", split[0]) == 0)
			cylindre->pos.x = ft_atof(split[1]);
		if (ft_strcasecmp("y", split[0]) == 0)
			cylindre->pos.y = ft_atof(split[1]);
		if (ft_strcasecmp("z", split[0]) == 0)
			cylindre->pos.z = ft_atof(split[1]);
		if (ft_strcasecmp("a", split[0]) == 0)
			cylindre->a = ft_atof(split[1]);
		if (ft_strcasecmp("b", split[0]) == 0)
			cylindre->b = ft_atof(split[1]);
		if (ft_strcasecmp("r", split[0]) == 0)
			cylindre->r = ft_atof(split[1]);
		if (ft_strcasecmp("color", split[0]) == 0)
			cylindre->color = ft_readcolor(split[1]);
	}
	ft_freesplit(split);
}

void	ft_readcylindre(t_scene *s, int fd, char *line, int *i)
{
	t_cylindre	*cylindre;

	cylindre = (t_cylindre*)malloc(sizeof(t_cylindre));
	ft_addlist(s, cylindre, CYLINDRE);
	if (s->error == 1)
		return ;
	cylindre->pos.x = 0;
	cylindre->pos.y = 0;
	cylindre->pos.z = 0;
	cylindre->a = 0;
	cylindre->b = 0;
	cylindre->r = 10;
	cylindre->color = WHITE;
	while (ft_strlen(line) && *i == 1)
	{
		*i = get_next_line(fd, &line);
		if (ft_strlen(line))
			ft_cylindredata(cylindre, line);
	}
}
