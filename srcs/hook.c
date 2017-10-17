/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 11:58:47 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/16 17:05:19 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void		hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 17, 1L << 0, hook_close, mlx);
}

void		forward_backward_or_getb(t_mlx *mlx)
{
	if (KEYCODE == 126)
	{
		if (GRID[(int)(CAM_Y)][(int)(CAM_X + (cos((ANGLE * M_PI) / 180) * 0.12) * 1.5)] == 0)
				CAM_X = CAM_X + (cos((ANGLE * M_PI) / 180) * 0.12);
		if (GRID[(int)(CAM_Y + (sin((ANGLE * M_PI) / 180) * 0.12) * 1.5)][(int)(CAM_X)] == 0)
				CAM_Y = CAM_Y + (sin((ANGLE * M_PI) / 180) * 0.12);
	}
	else if (KEYCODE == 125)
	{
		if (GRID[(int)(CAM_Y)][(int)(CAM_X - (cos((ANGLE * M_PI) / 180) * 0.12) * 1.5)] == 0)
			CAM_X = CAM_X - (cos((ANGLE * M_PI) / 180) * 0.12);
		if (GRID[(int)(CAM_Y - (sin((ANGLE * M_PI) / 180) * 0.12) * 1.5)][(int)(CAM_X)] == 0)	
			CAM_Y = CAM_Y - (sin((ANGLE * M_PI) / 180) * 0.12);
	}
	else if (KEYCODE == 51)
	{
		CAM_X = CAM_X_OR;
		CAM_Y = CAM_Y_OR;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	delete_image(mlx);
	mlx->image = new_image(mlx);
}

void		right_left_or_spin(t_mlx *mlx)
{
	printf("==========================================>ANGLE =%f\n", ANGLE);
	if (KEYCODE == 124)
	{
		ANGLE = ANGLE + 2.2;
	}
	else if (KEYCODE == 123)
	{
		ANGLE = ANGLE - 2.2;
	}
	else
	{
		if (ANGLE < 180)
			ANGLE = ANGLE + 180;
		else
			ANGLE = ANGLE - 180;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	delete_image(mlx);
	mlx->image = new_image(mlx);
}

int			key_press(int keycode, t_mlx *mlx)
{
	KEYCODE = keycode;
	if (KEYCODE == 124 || KEYCODE == 123 || KEYCODE == 49)
		right_left_or_spin(mlx);
	if (KEYCODE == 126 || KEYCODE == 125 || KEYCODE == 51)
		forward_backward_or_getb(mlx);
	if (KEYCODE == 53)
		mlx_free(mlx);
	raytracing(mlx);
	return (0);
}

int			hook_close(t_mlx *mlx)
{
	mlx_free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
