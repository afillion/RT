/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:08:03 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/14 17:07:10 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(little);
	i = 0;
	while ((i + size <= ft_strlen(big)) && (i + size <= len))
	{
		if (ft_strnequ(big + i, little, size))
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
