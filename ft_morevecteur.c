/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morevecteur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:22:55 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/26 17:44:14 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vecteur	ft_rotatevecteurx(t_vecteur v, double a)
{
	t_vecteur	u;

	u.x = v.x;
	u.y = v.y * cos(a) + v.z * sin(a);
	u.z = v.z * cos(a) - v.y * sin(a);
	return (u);
}

t_vecteur	ft_rotatevecteury(t_vecteur v, double a)
{
	t_vecteur	u;

	u.x = v.x * cos(a) - v.z * sin(a);
	u.y = v.y;
	u.z = v.z * cos(a) + v.x * sin(a);
	return (u);
}

t_vecteur	ft_rotatevecteurz(t_vecteur v, double a)
{
	t_vecteur	u;

	u.x = v.x * cos(a) + v.y * sin(a);
	u.y = v.y * cos(a) - v.x * sin(a);
	u.z = v.z;
	return (u);
}

t_vecteur	ft_rotatevecteur(t_vecteur v, double x, double y, double z)
{
	v = ft_rotatevecteurx(v, x);
	v = ft_rotatevecteury(v, y);
	v = ft_rotatevecteurz(v, z);
	return (v);
}

t_vecteur	ft_rotatearound(t_vecteur v, t_vecteur a, double t)
{
	t_vecteur	u;
	double		c;
	double		s;

	c = cos(t);
	s = sin(t);
	u.x = v.x * (a.x * a.x * (1 - c) + c)
		+ v.y * (a.x * a.y * (1 - c) + a.z * s)
		+ v.z * (a.x * a.z * (1 - c) - a.y * s);
	u.y = v.x * (a.x * a.y * (1 - c) - a.z * s)
		+ v.y * (a.y * a.y * (1 - c) + c)
		+ v.z * (a.y * a.z * (1 - c) + a.x * s);
	u.z = v.x * (a.x * a.z * (1 - c) + a.y * s)
		+ v.y * (a.y * a.z * (1 - c) - a.x * s)
		+ v.z * (a.z * a.z * (1 - c) + c);
	return (u);
}
