/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:31:31 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/13 19:17:51 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void		ft_addlist(t_scene *s, void *objet, int type)
{
	t_listobj	*new;

	new = (t_listobj*)malloc(sizeof(t_listobj));
	if (new == NULL || objet == NULL)
	{
		s->error = 1;
		return ;
	}
	new->objet = objet;
	new->type = type;
	new->next = s->list;
	s->list = new;
}
