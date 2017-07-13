/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:19:00 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 18:38:53 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

int		ft_distance(double a, double b, double c, t_rayon *ray)
{
	double	det;
	double	t1;
	double	t2;

	det = b * b - 4 * a * c;
	if (det < 0)
		return (0);
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t1 < 0.01 && t2 < 0.01)
		return (0);
	else if (t1 >= 0.01 && t2 >= 0.01)
		ray->t = fmin(fmin(t1, t2), ray->t);
	else
		ray->t = fmin(fmax(t1, t2), ray->t);
	if (ray->t == t1 || ray->t == t2)
		return (1);
	return (0);
}
