/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intercylindre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:15:25 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 17:40:59 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_intercylindre(t_rayon *ray, t_cylindre *cylindre)
{
	t_rayon		ray2;
	t_vecteur	v;
	double		a;
	double		b;
	double		c;

	v = ft_getvecteur(cylindre->pos, ray->pos);
	v = ft_rotatevecteur(v, -cylindre->a, -cylindre->b, 0);
	ray2.pos = ft_translation(cylindre->pos, v);
	ray2.vec = ft_rotatevecteur(ray->vec, -cylindre->a, -cylindre->b, 0);
	a = ray2.vec.x * ray2.vec.x + ray2.vec.y * ray2.vec.y;
	b = 2 * (ray2.vec.x * v.x + ray2.vec.y * v.y);
	c = v.x * v.x + v.y * v.y - cylindre->r * cylindre->r;
	return (ft_distance(a, b, c, ray));
}
