/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 05:21:09 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/14 20:19:43 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_get_color(t_mlx *mlx)
{
	if (WALL_X == floor(WALL_X))
	{
		if (ANGLE_ACT > 90 && ANGLE_ACT <= 270)
			COLOR = EAST;
		if ((ANGLE_ACT >= 0 && ANGLE_ACT <= 90) ||
				(ANGLE_ACT > 270 && ANGLE_ACT <= 360))
			COLOR = WEST;
	}
	if (WALL_Y == floor(WALL_Y))
	{
		if (ANGLE_ACT >= 180 && ANGLE_ACT < 360)
			COLOR = NORTH;
		if (ANGLE_ACT >= 0 && ANGLE_ACT < 180)
			COLOR = SOUTH;
	}
}
