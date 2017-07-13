/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnormale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:55:06 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 15:45:16 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vecteur	ft_getnormale(t_point pos, t_listobj *liste)
{
	t_vecteur	v;

	if (liste->type == SPHERE)
	{
		v = ft_getvecteur(((t_sphere*)liste->objet)->pos, pos);
		return (ft_normalizevecteur(v));
	}
	else if (liste->type == PLAN)
		return (ft_getnormplan((t_plan*)liste->objet));
	else if (liste->type == CYLINDRE)
		return (ft_getnormcyl(pos, (t_cylindre*)liste->objet));
	else if (liste->type == CONE)
		return (ft_getnormcone(pos, (t_cone*)liste->objet));
	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}
