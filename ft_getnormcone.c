/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnormcone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:25:44 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 15:46:28 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vecteur	ft_getnormcone(t_point pos, t_cone *cone)
{
	t_vecteur	v;

	v = ft_getvecteur(cone->pos, pos);
	v = ft_rotatevecteur(v, -cone->a, -cone->b, 0);
	if (v.z > 0)
	{
		v.z = 0;
		v = ft_normalizevecteur(v);
		v.z = -cone->c;
	}
	else
	{
		v.z = 0;
		v = ft_normalizevecteur(v);
		v.z = cone->c;
	}
	v = ft_rotatevecteur(v, cone->a, cone->b, 0);
	v = ft_normalizevecteur(v);
	return (v);
}
