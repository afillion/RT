/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:18:09 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/06 15:14:21 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// int		ft_move(int keycode, t_camera *cam)
// {
// 	if (keycode == 84)
// 		cam->pos = ft_translation(cam->pos, ft_multvecteur(cam->vec, -10));
// 	else if (keycode == 86)
// 		cam->pos = ft_translation(cam->pos, ft_multvecteur(cam->rightvec, -10));
// 	else if (keycode == 88)
// 		cam->pos = ft_translation(cam->pos, ft_multvecteur(cam->rightvec, 10));
// 	else if (keycode == 91)
// 		cam->pos = ft_translation(cam->pos, ft_multvecteur(cam->vec, 10));
// 	else if (keycode == 123)
// 		cam->vec = ft_rotatevecteur(cam->vec, 0, 0, (double)(1) / 16);
// 	else if (keycode == 124)
// 		cam->vec = ft_rotatevecteur(cam->vec, 0, 0, (double)(-1) / 16);
// 	else if (keycode == 125)
// 		cam->vec = ft_rotatearound(cam->vec, cam->rightvec, (double)(-1) / 16);
// 	else if (keycode == 126)
// 		cam->vec = ft_rotatearound(cam->vec, cam->rightvec, (double)(1) / 16);
// 	else
// 		return (0);
// 	return (1);
// }