/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:39:30 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/07 16:21:50 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *big, char const *little)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(little);
	i = 0;
	while (i + size <= ft_strlen(big))
	{
		if (ft_strnequ(big + i, little, size))
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
