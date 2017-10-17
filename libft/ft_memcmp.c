/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:28:58 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/24 16:32:26 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	i;

	str1 = (unsigned char*)ptr1;
	str2 = (unsigned char*)ptr2;
	i = 0;
	while (i < num)
	{
		if (str1[i] - str2[i] == 0)
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}
