/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readplan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:41:51 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/15 17:30:47 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_plandata(t_plan *plan, char *line)
{
	char	**split;

	split = ft_strsplit(line, ':');
	if (split == NULL)
		return ;
	if (split[1] != NULL)
	{
		if (ft_strcasecmp("a", split[0]) == 0)
			plan->a = ft_atof(split[1]);
		if (ft_strcasecmp("b", split[0]) == 0)
			plan->b = ft_atof(split[1]);
		if (ft_strcasecmp("c", split[0]) == 0)
			plan->c = ft_atof(split[1]);
		if (ft_strcasecmp("d", split[0]) == 0)
			plan->d = ft_atof(split[1]);
		if (ft_strcasecmp("color", split[0]) == 0)
			plan->color = ft_readcolor(split[1]);
	}
	ft_freesplit(split);
}

void	ft_readplan(t_scene *s, int fd, char *line, int *i)
{
	t_plan		*plan;

	plan = (t_plan*)malloc(sizeof(t_plan));
	ft_addlist(s, plan, PLAN);
	if (s->error == 1)
		return ;
	plan->a = 0;
	plan->b = 0;
	plan->c = 1;
	plan->d = 20;
	plan->color = WHITE;
	while (ft_strlen(line) && *i == 1)
	{
		*i = get_next_line(fd, &line);
		if (ft_strlen(line))
			ft_plandata(plan, line);
	}
}
