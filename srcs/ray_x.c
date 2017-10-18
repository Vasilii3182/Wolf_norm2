/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:00:11 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/18 22:39:26 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	exception_x(t_mlx *mlx, double angle)
{
	int sign;

	sign = 1;
	if (angle >= 270 && angle < 271)
		sign = -1;
	RAY_X = CAM_X;
	RAY_Y = floor(CAM_Y + sign);
	while (check_if_wall(mlx) <= 0)
	{
		if (check_if_wall(mlx) == -1 || check_if_wall(mlx) == 1)
			break ;
		RAY_Y = RAY_Y + sign;
	}
	HITX_X = RAY_X;
	HITX_Y = RAY_Y;
}

int		init_x(t_mlx *mlx, double angle_act)
{
	if (angle_act == 90 | angle_act == 270)
	{
		exception_x(mlx, angle_act);
		return (0);
	}
	if (angle_act < 90 || angle_act > 270)
	{
		RAY_X = ceil(CAM_X);
		return (1);
	}
	RAY_X = floor(CAM_X);
	return (-1);
}

void	x_axis(t_mlx *mlx, double angle_act)
{
	int		right_or_left;
	double	x_per_y;
	double	y_per_x;

	if ((right_or_left = init_x(mlx, angle_act)) == 0)
		return ;
	RAY_Y = CAM_Y + ((RAY_X - CAM_X) * tan((angle_act * M_PI) / 180));
	x_per_y = (RAY_X - CAM_X) / fabs(RAY_Y - CAM_Y);
	y_per_x = (RAY_Y - CAM_Y) / fabs(RAY_X - CAM_X);
	while (check_if_wall(mlx) <= 0)
	{
		if (check_if_wall(mlx) == -1 || check_if_wall(mlx) == 1)
			break ;
		RAY_X = RAY_X + right_or_left;
		RAY_Y = RAY_Y + y_per_x;
	}
	HITX_X = RAY_X;
	HITX_Y = RAY_Y;
}
