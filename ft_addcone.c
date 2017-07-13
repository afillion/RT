/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addcone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:20:10 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 16:57:39 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_addcone(t_scene *s, t_point pos, t_point t, int color)
{
	t_cone		*cone;
	t_listobj	*newobj;

	cone = (t_cone*)malloc(sizeof(t_cone));
	newobj = (t_listobj*)malloc(sizeof(t_listobj));
	if (cone == NULL || newobj == NULL)
	{
		s->error = 1;
		return ;
	}
	cone->pos = pos;
	cone->a = t.x;
	cone->b = t.y;
	cone->c = t.z;
	cone->color = color;
	newobj->objet = cone;
	newobj->type = CONE;
	newobj->next = s->list;
	s->list = newobj;
}
