/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:28:54 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/27 16:07:54 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t num)
{
	size_t i;
	size_t len_dest;
	size_t len_src;

	i = 0;
	len_dest = (size_t)ft_strlen(dest);
	len_src = (size_t)ft_strlen(src);
	if (num == 0)
		return (len_src);
	if (num < len_dest)
		return (num + len_src);
	while (src[i] != '\0' && (len_dest + 1 + i) < num)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
