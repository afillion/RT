/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addspot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:33:24 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 17:45:42 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_addspot(t_scene *s, t_point pos, double r)
{
	t_spot		*spot;

	spot = (t_spot*)malloc(sizeof(t_spot));
	if (spot == NULL)
	{
		s->error = 1;
		return ;
	}
	spot->pos = pos;
	spot->power = r;
	spot->next = s->spot;
	s->spot = spot;
}
