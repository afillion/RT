/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:08:33 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/17 19:29:56 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atofdec(const char *str)
{
	double		d;
	int			n;

	d = 0;
	while (ft_isdigit(*str))
	{
		d *= 10;
		d += *str - '0';
		str++;
	}
	if (*str == '.')
	{
		str++;
		n = -1;
		while (ft_isdigit(*str))
		{
			d += (*str - '0') * ft_pow(10, n);
			n--;
			str++;
		}
	}
	if (ft_toupper(*str) == 'E')
		d *= ft_pow(10, ft_atoi(str + 1));
	return (d);
}

double		ft_atof(const char *str)
{
	if (ft_isspace(*str))
		return (ft_atof(str + 1));
	if (*str == '+')
		return (ft_atofdec(str + 1));
	if (*str == '-')
		return (-ft_atofdec(str + 1));
	if (ft_isdigit(*str))
		return (ft_atofdec(str));
	return (0);
}
