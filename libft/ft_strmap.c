/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:25:30 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/08 17:15:11 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	if (s && f)
	{
		s2 = ft_strnew(ft_strlen(s));
		if (s2 == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			s2[i] = f(s[i]);
			i++;
		}
		return (s2);
	}
	return (NULL);
}
