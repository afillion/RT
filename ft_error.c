/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:04:50 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/08 18:25:23 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

int		ft_error(int e)
{
	if (e == 1)
		ft_putendl("malloc error");
	if (e == 2)
		ft_putendl("usage : ./rt FILEPATH");
	if (e == 3)
		ft_putendl("File not found");
	return (0);
}
