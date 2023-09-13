/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:39:21 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:39:21 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_bonus.h"
#include <stdlib.h>

static void	init_ftmlx(t_mlx *mlx)
{
	mlx->ptr.mlx_ptr = NULL;
	mlx->ptr.win_ptr = NULL;
	mlx->ptr.img_ptr = NULL;
	mlx->ptr.texture_ptr = NULL;
	mlx->ptr.normal_ptr = NULL;
	mlx->img.addr = NULL;
	mlx->img.bits_per_pixel = 0;
	mlx->img.size_line = 0;
	mlx->img.endian = 0;
	mlx->texture.info.addr = NULL;
	mlx->texture.info.bits_per_pixel = 0;
	mlx->texture.info.size_line = 0;
	mlx->texture.info.endian = 0;
}

static void	*set_ptr(t_mlx *mlx)
{
	mlx->ptr.mlx_ptr = mlx_init();
	if (mlx->ptr.mlx_ptr == NULL)
		return (NULL);
	mlx->ptr.win_ptr = mlx_new_window(mlx->ptr.mlx_ptr, \
									WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (mlx->ptr.win_ptr == NULL)
		return (NULL);
	mlx->ptr.img_ptr = mlx_new_image(mlx->ptr.mlx_ptr, \
									WIN_WIDTH, WIN_HEIGHT);
	if (mlx->ptr.img_ptr == NULL)
		return (NULL);
	mlx->ptr.texture_ptr = mlx_xpm_file_to_image(mlx->ptr.mlx_ptr, \
		"./image/earth.xpm", &mlx->texture.width, &mlx->texture.height);
	if (mlx->ptr.texture_ptr == NULL)
		return (NULL);
	mlx->ptr.normal_ptr = mlx_xpm_file_to_image(mlx->ptr.mlx_ptr, \
		"./image/earth_normal.xpm", &mlx->normal.width, &mlx->normal.height);
	if (mlx->ptr.normal_ptr == NULL)
		return (NULL);
	return (mlx);
}

void	set_img_data(t_mlx *mlx)
{
	mlx->img.addr = mlx_get_data_addr(mlx->ptr.img_ptr, \
		&mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);
	mlx->texture.info.addr = mlx_get_data_addr(mlx->ptr.texture_ptr, \
		&mlx->texture.info.bits_per_pixel, &mlx->texture.info.size_line, \
		&mlx->texture.info.endian);
	mlx->normal.info.addr = mlx_get_data_addr(mlx->ptr.normal_ptr, \
		&mlx->normal.info.bits_per_pixel, &mlx->normal.info.size_line, \
		&mlx->normal.info.endian);
}

void	*init_all(t_mlx *mlx)
{
	init_ftmlx(mlx);
	if (set_ptr(mlx) == NULL)
		return (NULL);
	set_img_data(mlx);
	return (mlx);
}
