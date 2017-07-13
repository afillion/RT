/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:52:26 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/15 17:30:56 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_conedata(t_cone *cone, char *line)
{
	char	**split;

	split = ft_strsplit(line, ':');
	if (split == NULL)
		return ;
	if (split[1] != NULL)
	{
		if (ft_strcasecmp("x", split[0]) == 0)
			cone->pos.x = ft_atof(split[1]);
		if (ft_strcasecmp("y", split[0]) == 0)
			cone->pos.y = ft_atof(split[1]);
		if (ft_strcasecmp("z", split[0]) == 0)
			cone->pos.z = ft_atof(split[1]);
		if (ft_strcasecmp("a", split[0]) == 0)
			cone->a = ft_atof(split[1]);
		if (ft_strcasecmp("b", split[0]) == 0)
			cone->b = ft_atof(split[1]);
		if (ft_strcasecmp("c", split[0]) == 0)
			cone->c = ft_atof(split[1]);
		if (ft_strcasecmp("color", split[0]) == 0)
			cone->color = ft_readcolor(split[1]);
	}
	ft_freesplit(split);
}

void	ft_readcone(t_scene *s, int fd, char *line, int *i)
{
	t_cone		*cone;

	cone = (t_cone*)malloc(sizeof(t_cone));
	ft_addlist(s, cone, CONE);
	if (s->error == 1)
		return ;
	cone->pos.x = 0;
	cone->pos.y = 0;
	cone->pos.z = 0;
	cone->a = 0;
	cone->b = 0;
	cone->c = 10;
	cone->color = WHITE;
	while (ft_strlen(line) && *i == 1)
	{
		*i = get_next_line(fd, &line);
		if (ft_strlen(line))
			ft_conedata(cone, line);
	}
}
