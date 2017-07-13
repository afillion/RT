/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:36:06 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/07 17:35:47 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*s2;
	size_t	i;

	s2 = ft_strnew(ft_strlen(s1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
