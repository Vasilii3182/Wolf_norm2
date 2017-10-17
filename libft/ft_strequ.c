/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:26:17 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/24 16:49:49 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int x;

	if (s1 == NULL || s2 == NULL)
		return (0);
	x = ft_strcmp((char*)s1, (char*)s2);
	if (x == 0)
		return (1);
	return (0);
}
