/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnormplan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:22:23 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 15:45:42 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vecteur	ft_getnormplan(t_plan *plan)
{
	t_vecteur	v;

	v.x = plan->a;
	v.y = plan->b;
	v.z = plan->c;
	v = ft_normalizevecteur(v);
	return (v);
}
