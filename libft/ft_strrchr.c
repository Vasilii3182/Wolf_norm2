/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:16:01 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/25 18:25:58 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int value)
{
	int		i;
	char	*p;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == value)
		{
			p = &str[i];
			return (p);
		}
		i--;
	}
	return (NULL);
}
