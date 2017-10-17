/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:11:05 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/25 14:04:26 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *cpy, char *src, size_t num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{
		if (src[i] == '\0')
		{
			while (i < num)
			{
				cpy[i] = '\0';
				i++;
			}
		}
		else
		{
			cpy[i] = src[i];
			i++;
		}
	}
	return (cpy);
}
