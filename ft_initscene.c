/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initscene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:45:10 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/15 18:38:35 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

t_scene		*ft_initscene(void)
{
	t_scene		*s;

	s = (t_scene*)malloc(sizeof(t_scene));
	if (s == NULL)
		return (s);
	s->name = NULL;
	s->cam = (t_camera*)malloc(sizeof(t_camera));
	s->list = NULL;
	s->spot = NULL;
	if (s->cam == NULL)
		s->error = 1;
	else
		s->error = 0;
	s->cam->xres = 800;
	s->cam->yres = 600;
	s->cam->pos.x = -200;
	s->cam->pos.y = 0;
	s->cam->pos.z = 0;
	s->cam->vec.x = 1;
	s->cam->vec.y = 0;
	s->cam->vec.z = 0;
	s->cam->viewdist = 1;
	s->cam->viewwidth = 1.2;
	s->cam->viewheight = 0.9;
	return (s);
}
