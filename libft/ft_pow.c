/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 19:26:15 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/17 19:28:00 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_pow(double a, int b)
{
	double	c;

	c = 1;
	while (b != 0)
	{
		if (b > 0)
		{
			c *= a;
			b--;
		}
		if (b < 0)
		{
			c /= a;
			b++;
		}
	}
	return (c);
}
