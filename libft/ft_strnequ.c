/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:26:17 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/29 18:46:27 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int x;

	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	x = ft_strncmp((char*)s1, (char*)s2, (int)n);
	if (x == 0)
		return (1);
	return (0);
}
