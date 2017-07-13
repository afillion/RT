/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:05:44 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/07 17:54:07 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t	i;
	void	*tmp;

	tmp = (void*)malloc(len);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char*)tmp)[i] = ((unsigned char*)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)tmp)[i];
		i++;
	}
	free(tmp);
	return (dst);
}
