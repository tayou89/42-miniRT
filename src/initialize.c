/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:38:27 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:38:28 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"
#include <stdlib.h>

static void	init_ftmlx(t_mlx *mlx)
{
	mlx->ptr.mlx_ptr = NULL;
	mlx->ptr.win_ptr = NULL;
	mlx->ptr.img_ptr = NULL;
	mlx->img.addr = NULL;
	mlx->img.bits_per_pixel = 0;
	mlx->img.size_line = 0;
	mlx->img.endian = 0;
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
	mlx->img.addr = mlx_get_data_addr(mlx->ptr.img_ptr, \
									&mlx->img.bits_per_pixel, \
									&mlx->img.size_line, \
									&mlx->img.endian);
	return (mlx);
}

void	*init_all(t_mlx *mlx)
{
	init_ftmlx(mlx);
	if (set_ptr(mlx) == NULL)
		return (NULL);
	return (mlx);
}
