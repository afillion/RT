/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:58:55 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/08 17:25:06 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	if (s1 && s2)
	{
		s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (s3 == NULL)
			return (NULL);
		i = 0;
		while (*s1 != '\0')
		{
			s3[i] = *s1;
			s1++;
			i++;
		}
		while (*s2 != '\0')
		{
			s3[i] = *s2;
			s2++;
			i++;
		}
		return (s3);
	}
	return (NULL);
}
