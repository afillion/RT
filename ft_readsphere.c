/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readsphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:16:43 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/15 17:21:47 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_spheredata(t_sphere *sphere, char *line)
{
	char	**split;

	split = ft_strsplit(line, ':');
	if (split == NULL)
		return ;
	if (split[1] != NULL)
	{
		if (ft_strcasecmp("x", split[0]) == 0)
			sphere->pos.x = ft_atof(split[1]);
		if (ft_strcasecmp("y", split[0]) == 0)
			sphere->pos.y = ft_atof(split[1]);
		if (ft_strcasecmp("z", split[0]) == 0)
			sphere->pos.z = ft_atof(split[1]);
		if (ft_strcasecmp("r", split[0]) == 0)
			sphere->r = ft_atof(split[1]);
		if (ft_strcasecmp("color", split[0]) == 0)
			sphere->color = ft_readcolor(split[1]);
	}
	ft_freesplit(split);
}

void	ft_readsphere(t_scene *s, int fd, char *line, int *i)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	ft_addlist(s, sphere, SPHERE);
	if (s->error == 1)
		return ;
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = 0;
	sphere->r = 10;
	sphere->color = WHITE;
	while (ft_strlen(line) && *i == 1)
	{
		*i = get_next_line(fd, &line);
		if (ft_strlen(line))
			ft_spheredata(sphere, line);
	}
}
