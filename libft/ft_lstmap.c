/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:58:14 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/29 10:22:33 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	new = NULL;
	tmp = NULL;
	while (lst)
	{
		if (new == NULL)
		{
			new = f(lst);
			tmp = new;
		}
		else
		{
			new->next = f(lst);
			new = new->next;
		}
		lst = lst->next;
	}
	return (tmp);
}
