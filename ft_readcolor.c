/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 17:11:00 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/22 09:50:12 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

int		ft_readcolor(char *color)
{
	if (ft_strncasecmp(color, "0x", 2) == 0)
		return (ft_min(ft_hexatoi(color + 2), WHITE));
	if (ft_isdigit(*color) && ft_atoi(color) <= 16777215)
		return (ft_min(ft_atoi(color), WHITE));
	if (ft_strcasecmp(color, "RED") == 0)
		return (RED);
	if (ft_strcasecmp(color, "BLUE") == 0)
		return (BLUE);
	if (ft_strcasecmp(color, "GREEN") == 0)
		return (GREEN);
	if (ft_strcasecmp(color, "DARKBLUE") == 0)
		return (DARKBLUE);
	if (ft_strcasecmp(color, "DARKRED") == 0)
		return (DARKRED);
	if (ft_strcasecmp(color, "DARKGREEN") == 0)
		return (DARKGREEN);
	if (ft_strcasecmp(color, "GREY") == 0)
		return (GREY);
	if (ft_strcasecmp(color, "WHITE") == 0)
		return (WHITE);
	return (WHITE);
}
