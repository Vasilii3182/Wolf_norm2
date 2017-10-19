/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:34:16 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/19 13:49:04 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_mlx	*initialize_win(void)
{
	t_mlx *mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if (((mlx->mlx = mlx_init()) == NULL) ||
			(mlx->parameters = ft_memalloc(sizeof(t_params))) == NULL ||
			(mlx->ray = ft_memalloc(sizeof(t_ray))) == NULL)
		return (mlx_free(mlx));
	return (mlx);
}

t_mlx	*mlx_free(t_mlx *mlx)
{
	if (mlx->win != NULL)
	{
		if (GRID != NULL)
			free(GRID);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	if (mlx->image != NULL)
		delete_image(mlx);
	if (mlx->parameters != NULL)
		ft_memdel((void **)&mlx->parameters);
	if (mlx->ray != NULL)
		ft_memdel((void **)&mlx->ray);
	ft_memdel((void **)&mlx);
	exit(0);
	return (NULL);
}
