/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:49:39 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/25 09:17:50 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned long int	i;
	unsigned char		*dest2;
	unsigned char		*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	i = 0;
	while (i < num)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
