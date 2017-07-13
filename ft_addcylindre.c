/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addcylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:58:22 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 16:58:00 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_addcylindre(t_scene *s, t_point pos, t_point t, int color)
{
	t_cylindre	*cylindre;
	t_listobj	*newobj;

	cylindre = (t_cylindre*)malloc(sizeof(t_cylindre));
	newobj = (t_listobj*)malloc(sizeof(t_listobj));
	if (cylindre == NULL || newobj == NULL)
	{
		s->error = 1;
		return ;
	}
	cylindre->pos = pos;
	cylindre->a = t.x;
	cylindre->b = t.y;
	cylindre->r = t.z;
	cylindre->color = color;
	newobj->objet = cylindre;
	newobj->type = CYLINDRE;
	newobj->next = s->list;
	s->list = newobj;
}
