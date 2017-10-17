/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:52:36 by ofranco           #+#    #+#             */
/*   Updated: 2017/04/13 21:24:03 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(str);
	dup = (char*)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	dup[len] = '\0';
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
