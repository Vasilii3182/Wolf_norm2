/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:06:44 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/16 14:46:36 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int     check_if_wall2(t_mlx *mlx)
{
	if (ANGLE_ACT >= 180 && ANGLE_ACT < 270)
	{
		if (RAY_Y - 1 >= Y_NBR || RAY_X - 1 >= Y_NBR ||
				RAY_X - 1 < 0 || RAY_Y - 1 < 0)
			return (-1);
		if (GRID[(int)ceil(RAY_Y - 1)][(int)ceil(RAY_X - 1)] == 1)
			return (1);
	}
	if (ANGLE_ACT >= 270 && ANGLE_ACT < 360)
	{
		if (RAY_Y - 1 >= Y_NBR || RAY_X >= Y_NBR || RAY_X < 0 || RAY_Y - 1 < 0)
			return (-1);
		if (GRID[(int)ceil(RAY_Y - 1)][(int)floor(RAY_X)] == 1)
			return (1);
	}
	return (0);
}

static int     check_if_wall(t_mlx *mlx)
{
	if (ANGLE_ACT >= 0 && ANGLE_ACT <= 90)
	{
		if (RAY_Y >= Y_NBR || RAY_X >= Y_NBR || RAY_X < 0 || RAY_Y < 0)
			return (-1);
		if (GRID[(int)RAY_Y][(int)RAY_X] == 1)
			return (1);
	}
	if (ANGLE_ACT > 90 && ANGLE_ACT < 180)
	{
		if (RAY_Y >= Y_NBR || RAY_X - 1 >= Y_NBR || RAY_X - 1 < 0 || RAY_Y < 0)
			return (-1);
		if (GRID[(int)floor(RAY_Y)][(int)ceil(RAY_X - 1)] == 1)
			return (1);
	}
	return (check_if_wall2(mlx));
}

void    exception_y(t_mlx *mlx, double angle)
{
	int sign;

	sign = 1;
	if (angle >= 180 && angle < 182)
		sign = -1;
	RAY_Y = CAM_Y;
	RAY_X = floor(CAM_X + sign);
	while (check_if_wall(mlx) <= 0)
	{
		if (check_if_wall(mlx) == -1 || check_if_wall(mlx) == 1)
			break ;
		RAY_X = RAY_X + sign;
	}
	HITX_X = RAY_X;
	HITX_Y = RAY_Y;
}

int     init_y(t_mlx *mlx, double angle_act)
{
	if (angle_act == 0 || angle_act == 180)
	{
		exception_y(mlx, angle_act);
		return (0);
	}
	if (angle_act < 180)
	{
		RAY_Y = ceil(CAM_Y);
		return (1);
	}
	RAY_Y = floor(CAM_Y);
	return (-1);
}

void    y_axis(t_mlx *mlx, double angle_act)
{
	int     up_or_down;
	double  x_per_y;
	double  y_per_x;

	if ((up_or_down = init_y(mlx, angle_act)) == 0)
		return ;
	RAY_X = CAM_X + ((RAY_Y - CAM_Y) / tan((angle_act * M_PI) / 180));
	x_per_y = (RAY_X - CAM_X) / fabs(RAY_Y - CAM_Y);
	y_per_x = (RAY_Y - CAM_Y) / fabs(RAY_X - CAM_X);
	while (check_if_wall(mlx) <= 0)
	{
		if (check_if_wall(mlx) == -1 || check_if_wall(mlx) == 1)
			break ;
		RAY_Y = RAY_Y + up_or_down;
		RAY_X = RAY_X + x_per_y;
	}
	HITY_X = RAY_X;
	HITY_Y = RAY_Y;
}
