/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:21:16 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/16 13:23:21 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	unsigned long int	i;
	char				*str;
	int					value;

	str = ptr;
	value = 0;
	i = 0;
	while (i < num)
	{
		str[i] = value;
		i++;
	}
}
