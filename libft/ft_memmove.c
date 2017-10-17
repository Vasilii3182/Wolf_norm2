/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:25:51 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/27 15:38:16 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	if (cdest < csrc)
		return (ft_memcpy(dest, src, num));
	while (num > 0)
	{
		cdest[num - 1] = csrc[num - 1];
		num--;
	}
	return (dest);
}
