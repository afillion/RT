/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addsphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:53:27 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 16:58:39 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_addsphere(t_scene *s, t_point pos, double r, int color)
{
	t_sphere	*sphere;
	t_listobj	*newobj;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	newobj = (t_listobj*)malloc(sizeof(t_listobj));
	if (sphere == NULL || newobj == NULL)
	{
		s->error = 1;
		return ;
	}
	sphere->pos = pos;
	sphere->r = r;
	sphere->color = color;
	newobj->objet = sphere;
	newobj->type = SPHERE;
	newobj->next = s->list;
	s->list = newobj;
}
