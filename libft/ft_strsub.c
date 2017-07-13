/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:50:16 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/08 17:19:18 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	s2 = ft_strnew(len);
	if (s2 == NULL || s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s[i + start];
		i++;
	}
	return (s2);
}
