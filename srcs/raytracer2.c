/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:40:22 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/19 14:09:32 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	short_len(t_mlx *mlx, double angle)
{
	double lenx;
	double leny;

	y_axis(mlx, angle);
	x_axis(mlx, angle);
	lenx = sqrt(pow((HITX_X - CAM_X), 2) + pow((HITX_Y - CAM_Y), 2));
	leny = sqrt(pow((HITY_X - CAM_X), 2) + pow((HITY_Y - CAM_Y), 2));
	if (lenx > leny)
	{
		WALL_X = HITY_X;
		WALL_Y = HITY_Y;
		return ;
	}
	if (leny > lenx)
	{
		WALL_X = HITX_X;
		WALL_Y = HITX_Y;
		return ;
	}
}

void	end_draw(t_mlx *mlx, int i, int xscreen, int yscreen)
{
	while ((i < HEIGHT_WALL) && (i < SCREEN_Y))
	{
		image_set_pixel(mlx, xscreen, yscreen);
		i++;
		yscreen++;
	}
	COLOR = 0x4C5756;
	while (i < SCREEN_Y)
	{
		image_set_pixel(mlx, xscreen, yscreen);
		yscreen++;
		i++;
	}
}

void	draw_column(t_mlx *mlx, int x)
{
	int xscreen;
	int yscreen;
	int i;

	xscreen = x;
	yscreen = 0;
	COLOR = 0xA0A0A0;
	while (yscreen < (int)floor(START_DRAW))
	{
		image_set_pixel(mlx, xscreen, yscreen);
		yscreen++;
	}
	i = 0;
	ft_get_color(mlx);
	end_draw(mlx, i, xscreen, yscreen);
}

void	raytracing(t_mlx *mlx)
{
	int		i;

	i = 0;
	TETA = -30.0;
	ANGLE = reset_angle(ANGLE);
	ANGLE_ACT = ANGLE - (FOV / 2);
	while (i < SCREEN_X)
	{
		ANGLE_ACT = reset_angle(ANGLE_ACT);
		short_len(mlx, ANGLE_ACT);
		DISTANCE = sqrt(pow((WALL_X - CAM_X), 2) + pow((WALL_Y - CAM_Y), 2));
		DIST_CORR = DISTANCE * cos((TETA * M_PI) / 180);
		HEIGHT_WALL = (HIGH_WALL / (DIST_CORR * 64)) * S_DIST;
		START_DRAW = (SCREEN_Y / 2) - (HEIGHT_WALL / 2);
		draw_column(mlx, i);
		i++;
		ANGLE_ACT = ANGLE_ACT + 0.046875;
		TETA = TETA + 0.046875;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
}
