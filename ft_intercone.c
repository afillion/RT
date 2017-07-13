/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intercone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:23:33 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 17:31:15 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_intercone(t_rayon *ray, t_cone *cone)
{
	t_rayon		ray2;
	t_vecteur	v;
	double		a;
	double		b;
	double		c;

	v = ft_getvecteur(cone->pos, ray->pos);
	v = ft_rotatevecteur(v, -cone->a, -cone->b, 0);
	ray2.pos = ft_translation(cone->pos, v);
	ray2.vec = ft_rotatevecteur(ray->vec, -cone->a, -cone->b, 0);
	a = ray2.vec.x * ray2.vec.x + ray2.vec.y * ray2.vec.y
		- cone->c * cone->c * ray2.vec.z * ray2.vec.z;
	b = 2 * (ray2.vec.x * v.x + ray2.vec.y * v.y
			- cone->c * cone->c * ray2.vec.z * v.z);
	c = v.x * v.x + v.y * v.y - cone->c * cone->c * v.z * v.z;
	return (ft_distance(a, b, c, ray));
}
