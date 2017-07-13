/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addplan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:56:02 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 16:58:35 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_addplan(t_scene *s, t_point pos, double r, int color)
{
	t_plan		*plan;
	t_listobj	*newobj;

	plan = (t_plan*)malloc(sizeof(t_plan));
	newobj = (t_listobj*)malloc(sizeof(t_listobj));
	if (plan == NULL || newobj == NULL)
	{
		s->error = 1;
		return ;
	}
	plan->a = pos.x;
	plan->b = pos.y;
	plan->c = pos.z;
	plan->d = r;
	plan->color = color;
	newobj->objet = plan;
	newobj->type = PLAN;
	newobj->next = s->list;
	s->list = newobj;
}
