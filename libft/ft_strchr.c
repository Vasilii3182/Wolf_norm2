/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:16:01 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/25 17:40:36 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int value)
{
	int		i;
	char	*p;

	i = 0;
	if (value == '\0')
	{
		while (str[i] != value)
			i++;
		if (str[i] == value)
		{
			p = &str[i];
			return (p);
		}
		return (NULL);
	}
	while (str[i] != value && value != '\0')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	p = &str[i];
	return (p);
}
