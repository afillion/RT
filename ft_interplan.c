/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interplan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:06:35 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/08 18:10:21 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_interplan(t_rayon *ray, t_plan *plan)
{
	double	t1;

	t1 = -(plan->a * ray->pos.x + plan->b * ray->pos.y
			+ plan->c * ray->pos.z + plan->d)
		/ (plan->a * ray->vec.x + plan->b * ray->vec.y + plan->c * ray->vec.z);
	if (t1 >= 0.01 && t1 <= ray->t)
	{
		ray->t = t1;
		return (1);
	}
	return (0);
}
