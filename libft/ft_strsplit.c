/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:59:51 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/08 17:25:58 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_countsplit(char const *s, char c)
{
	int		nb;
	int		i;
	int		new;

	new = 1;
	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && new == 1)
		{
			nb++;
			new = 0;
		}
		if (s[i] == c)
			new = 1;
		i++;
	}
	return (nb);
}

static char	*ft_cpysplit(char const *s, char c, int i)
{
	int				nb;
	unsigned int	j;
	size_t			new;

	new = 1;
	j = 0;
	nb = 0;
	while (nb <= i)
	{
		if (s[j] != c && new == 1)
		{
			nb++;
			new = 0;
		}
		if (s[j] == c)
			new = 1;
		j++;
	}
	j--;
	while (s[j + new] != c && s[j + new] != '\0')
		new++;
	return (ft_strsub(s, j, new));
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb;
	int		i;
	char	**split;

	if (s == NULL)
		return (NULL);
	nb = ft_countsplit(s, c);
	split = (char**)malloc(sizeof(char*) * (nb + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		split[i] = ft_cpysplit(s, c, i);
		if (split[i] == NULL)
			return (NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}
