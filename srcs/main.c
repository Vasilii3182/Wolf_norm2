/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:36:44 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/19 13:47:46 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double	reset_angle(double angle)
{
	if (angle < 0)
		angle = angle + 360;
	if (angle >= 360)
		angle = angle - 360;
	return (angle);
}

void	define_params(t_mlx *mlx)
{
	SCALE = 64;
	HIGH_WALL = 64;
	HIGH_CAM = HIGH_WALL / 2;
	CAM_X_OR = 1.50;
	CAM_Y_OR = 1.50;
	FOV = 60;
	ANGLE = 80;
	SCREEN_X = 1280;
	SCREEN_Y = 720;
	S_DIST = 1108;
	CAM_X = CAM_X_OR;
	CAM_Y = CAM_Y_OR;
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (!(argc == 1) || !(argv))
		return (-1);
	if ((mlx = initialize_win()) == NULL)
		return (-1);
	define_params(mlx);
	if ((mlx->win =
				mlx_new_window(mlx->mlx, SCREEN_X, SCREEN_Y, "wolf3d")) == NULL)
		mlx_free(mlx);
	if (parsing(mlx) == -1)
		return (-1);
	if ((mlx->image = new_image(mlx)) == NULL)
		mlx_free(mlx);
	raytracing(mlx);
	hooks(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
