/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:09:16 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/18 22:48:25 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "./../libft/libft.h"
# include "./../minilibx_macos/mlx.h"
# include <math.h>

# define GRID mlx->grid
# define Y_NBR mlx->count_y
# define SCALE mlx->parameters->scale
# define HIGH_WALL mlx->parameters->highwall
# define HIGH_CAM mlx->parameters->highcam
# define CAM_X_OR mlx->parameters->camxor
# define CAM_Y_OR mlx->parameters->camyor
# define FOV mlx->parameters->fov
# define ANGLE mlx->parameters->angle
# define SCREEN_X mlx->parameters->screenx
# define SCREEN_Y mlx->parameters->screeny
# define S_DIST mlx->parameters->sdist
# define CAM_X mlx->parameters->camx
# define CAM_Y mlx->parameters->camy
# define BPP mlx->image->bpp
# define RAY_X mlx->ray->rayx
# define RAY_Y mlx->ray->rayy
# define START_DRAW mlx->ray->start_draw
# define WALL_X mlx->ray->wall_x
# define WALL_Y mlx->ray->wall_y
# define HEIGHT_WALL mlx->ray->height_wall
# define DISTANCE mlx->ray->distance
# define DIST_CORR mlx->ray->dist_corrected
# define HITX_X mlx->ray->hitx_x
# define HITX_Y mlx->ray->hitx_y
# define HITY_X mlx->ray->hity_x
# define HITY_Y mlx->ray->hity_y
# define ANGLE_ACT mlx->parameters->angle_now
# define COLOR mlx->ray->color
# define KEYCODE mlx->ray->keyc
# define TETA mlx->ray->teta

# define NORTH 0x0C04F6
# define SOUTH 0xF6EE04
# define EAST 0x3BC610
# define WEST 0xF60434

typedef struct		s_ray {

	double			rayx;
	double			rayy;
	double			start_draw;
	double			wall_x;
	double			wall_y;
	double			distance;
	double			dist_corrected;
	double			height_wall;
	double			hitx_x;
	double			hitx_y;
	double			hity_x;
	double			hity_y;
	int				color;
	int				keyc;
	double			teta;

}					t_ray;

typedef struct		s_image {

	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;

}					t_image;

typedef struct		s_params {

	int				scale;
	int				highwall;
	int				highcam;
	double			camxor;
	double			camyor;
	int				fov;
	double			angle;
	int				screenx;
	int				screeny;
	int				sdist;
	double			camx;
	double			camy;
	double			angle_now;

}					t_params;

typedef struct		s_mlx {

	int				**grid;
	void			*win;
	void			*mlx;
	t_image			*image;
	t_params		*parameters;
	t_ray			*ray;
	int				count_y;

}					t_mlx;

int					parsing(t_mlx *mlx);
void				y_axis(t_mlx *mlx, double angle_act);
void				x_axis(t_mlx *mlx, double angle_act);
t_mlx				*initialize_win(void);
t_mlx				*mlx_free(t_mlx *mlx);
void				raytracing(t_mlx *mlx);
void				*new_image(t_mlx *mlx);
void				image_set_pixel(t_mlx *mlx, int x, int y);
int					key_func(int keycode, t_mlx *mlx);
void				*delete_image(t_mlx *mlx);
int					redraw_func(void *param);
void				ft_get_color(t_mlx *mlx);
void				hooks(t_mlx *mlx);
int					hook_close(t_mlx *mlx);
int					key_press(int keycode, t_mlx *mlx);
double				reset_angle(double angle);
int					check_grid(t_mlx *mlx);
int					check_char(char *str);
int					check_if_wall(t_mlx *mlx);
int					check_if_wall2(t_mlx *mlx);

#endif
