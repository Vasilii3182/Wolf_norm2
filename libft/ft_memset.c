/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:40:20 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/24 16:34:58 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned long int	i;
	char				*str;

	str = ptr;
	i = 0;
	while (i < num)
	{
		str[i] = value;
		i++;
	}
	return (ptr);
}
