/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initcam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:44:07 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/15 17:29:19 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_getrightvec(t_camera *cam)
{
	cam->rightvec.x = -cam->vec.y;
	cam->rightvec.y = cam->vec.x;
	cam->rightvec.z = 0;
	if (cam->rightvec.x == 0 && cam->rightvec.y == 0)
		cam->rightvec.y = 1;
	cam->rightvec = ft_normalizevecteur(cam->rightvec);
}

void	ft_getupvec(t_camera *cam)
{
	cam->upvec.x = cam->vec.y * cam->rightvec.z - cam->vec.z * cam->rightvec.y;
	cam->upvec.y = cam->vec.z * cam->rightvec.x - cam->vec.x * cam->rightvec.z;
	cam->upvec.z = cam->vec.x * cam->rightvec.y - cam->vec.y * cam->rightvec.x;
	if (cam->upvec.z < 0)
		cam->upvec = ft_multvecteur(cam->upvec, -1);
}

void	ft_initcam(t_camera *cam)
{
	if (cam->vec.x == 0 && cam->vec.y == 0 && cam->vec.z == 0)
		cam->vec.x = 1;
	cam->vec = ft_normalizevecteur(cam->vec);
	ft_getrightvec(cam);
	ft_getupvec(cam);
	cam->xindent = cam->viewwidth / cam->xres;
	cam->yindent = cam->viewheight / -cam->yres;
	cam->firstpix = ft_translation(cam->pos,
			ft_addvecteur(ft_multvecteur(cam->vec, cam->viewdist),
				ft_addvecteur(ft_multvecteur(cam->rightvec,
						cam->viewwidth / -2), ft_multvecteur(cam->upvec,
							cam->viewheight / 2))));
}
