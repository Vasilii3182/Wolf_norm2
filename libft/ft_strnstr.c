/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:45:40 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/29 18:06:46 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str1, char *str2, size_t num)
{
	unsigned int	i;

	i = ft_strlen(str2);
	if (*str2 == '\0')
		return (str1);
	while (*str1 != '\0' && num >= i)
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, i) == 0)
			return (str1);
		str1++;
		num--;
	}
	return (NULL);
}
