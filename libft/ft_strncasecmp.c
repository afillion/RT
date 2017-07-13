/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:15:38 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/13 19:01:10 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncasecmp(char const *s1, char const *s2, size_t n)
{
	if (((*s1 == '\0') && (*s2 == '\0')) || n == 0)
		return (0);
	if (ft_tolower(*s1) == ft_tolower(*s2))
		return (ft_strncasecmp(s1 + 1, s2 + 1, n - 1));
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
