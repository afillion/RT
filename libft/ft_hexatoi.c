/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 09:36:40 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/22 09:44:07 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa(char c)
{
	if (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	else
		return (0);
}

int		ft_hexatoi(const char *str)
{
	int n;

	n = 0;
	while (ft_ishexa(*str))
	{
		n *= 16;
		if (ft_isdigit(*str))
			n += (*str - '0');
		else
			n += (ft_toupper(*str) - 'A' + 10);
		str++;
	}
	return (n);
}
