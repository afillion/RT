/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:21:07 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/17 19:11:09 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_scene		*s;

	if (ac < 2)
		return (ft_error(2));
	s = ft_initscene();
	if (s == NULL || s->error == 1)
		return (ft_error(1));
	ft_readfile(s, av[1]);
	if (s->error)
		return (ft_error(s->error));
	ft_initcam(s->cam);
	ft_sdl(s); //anciennement ft_mlx
	return (0);
}
