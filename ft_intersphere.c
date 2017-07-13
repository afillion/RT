/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:14:32 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 17:43:28 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_intersphere(t_rayon *ray, t_sphere *sphere)
{
	double	a;
	double	b;
	double	c;
	t_point	p;

	p.x = ray->pos.x - sphere->pos.x;
	p.y = ray->pos.y - sphere->pos.y;
	p.z = ray->pos.z - sphere->pos.z;
	a = ray->vec.x * ray->vec.x + ray->vec.y * ray->vec.y
		+ ray->vec.z * ray->vec.z;
	b = 2 * (ray->vec.x * p.x + ray->vec.y * p.y + ray->vec.z * p.z);
	c = p.x * p.x + p.y * p.y + p.z * p.z - sphere->r * sphere->r;
	return (ft_distance(a, b, c, ray));
}
