/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:04:46 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/07 18:34:35 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int s;

	if (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		return (ft_atoi(str + 1));
	s = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		s = -1;
		str++;
	}
	n = 0;
	while (ft_isdigit(*str))
	{
		n *= 10;
		n += (*str - '0');
		str++;
	}
	return (n * s);
}
