/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:18:18 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/07 16:13:16 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	if ((n == 0) || ((*s1 == '\0') && (*s2 == '\0')))
		return (0);
	if (*s1 == *s2)
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
