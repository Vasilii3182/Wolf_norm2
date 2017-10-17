/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:49:39 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/29 19:39:29 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	unsigned long int		i;
	unsigned char			*dest2;
	unsigned const char		*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned const char*)src;
	i = 0;
	if (num == 0)
		return (NULL);
	while (i < num)
	{
		if ((char)src2[i] == (char)c)
		{
			dest2[i] = src2[i];
			return (dest2 + (i + 1));
		}
		else
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (NULL);
}
