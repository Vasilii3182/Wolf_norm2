/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:59:50 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/29 13:29:53 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char		*str;
	unsigned long int	i;
	void				*p;
	unsigned char		value2;

	i = 0;
	value2 = (unsigned char)value;
	str = (unsigned char*)ptr;
	while (i < num)
	{
		if ((unsigned char)str[i] == value2)
		{
			p = &str[i];
			return (p);
		}
		i++;
	}
	return (NULL);
}
