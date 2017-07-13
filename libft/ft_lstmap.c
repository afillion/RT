/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 20:03:48 by ltesson           #+#    #+#             */
/*   Updated: 2015/12/09 13:48:49 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_elem;

	if (lst->next)
	{
		new_elem = ft_lstmap(lst->next, f);
		ft_lstadd(&new_elem, f(lst));
		return (new_elem);
	}
	new_elem = f(lst);
	return (new_elem);
}
