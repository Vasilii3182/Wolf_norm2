/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:39:53 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/29 20:37:25 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

static int	ft_start_space(char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]) == 1)
	{
		i++;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char			*res;
	unsigned long	start;
	unsigned long	len;

	res = ft_strnew(1);
	if (s == NULL)
		return (NULL);
	if (ft_strlen((char*)s) == 0)
	{
		return (res);
	}
	start = ft_start_space((char*)s);
	len = ft_strlen((char*)s);
	if (start == len)
		return (res);
	len--;
	while (ft_isspace((char)s[len]) == 1)
	{
		if (len == 0)
			return (res);
		len--;
	}
	len = len - start;
	res = ft_strsub(s, start, (len + 1));
	return (res);
}
