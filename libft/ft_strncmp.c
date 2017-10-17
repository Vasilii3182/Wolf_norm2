/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:42:09 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/30 12:14:09 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t num)
{
	unsigned int i;

	i = 0;
	if (num == 0)
		return (0);
	if (s1[i] == '\0' || s2[i] == '\0')
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while (s1[i] != '\0' && s2[i] != '\0' && i < num)
	{
		if (s1[i] - s2[i] == 0)
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (i == num)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
