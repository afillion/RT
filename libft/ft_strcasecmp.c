/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:36:46 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/08 19:37:14 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(char const *s1, char const *s2)
{
	if ((*s1 == '\0') && (*s2 == '\0'))
		return (0);
	if (ft_tolower(*s1) == ft_tolower(*s2))
		return (ft_strcasecmp(s1 + 1, s2 + 1));
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
