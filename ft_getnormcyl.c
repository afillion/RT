/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnormcyl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:02:23 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 15:46:03 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vecteur	ft_getnormcyl(t_point pos, t_cylindre *cylindre)
{
	t_vecteur	v;

	v = ft_getvecteur(cylindre->pos, pos);
	v = ft_rotatevecteur(v, -cylindre->a, -cylindre->b, 0);
	v.z = 0;
	v = ft_rotatevecteur(v, cylindre->a, cylindre->b, 0);
	v = ft_normalizevecteur(v);
	return (v);
}
