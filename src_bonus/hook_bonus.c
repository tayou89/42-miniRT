/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:39:14 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:39:15 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "initialize_bonus.h"

void	exit_program(t_rt *scene)
{
	free_list(scene->data->obj);
	mlx_destroy_image(scene->mlx->ptr.mlx_ptr, scene->mlx->ptr.img_ptr);
	if (scene->mlx->ptr.texture_ptr != NULL)
		mlx_destroy_image(scene->mlx->ptr.mlx_ptr, scene->mlx->ptr.texture_ptr);
	if (scene->mlx->ptr.normal_ptr != NULL)
		mlx_destroy_image(scene->mlx->ptr.mlx_ptr, scene->mlx->ptr.normal_ptr);
	mlx_destroy_window(scene->mlx->ptr.mlx_ptr, scene->mlx->ptr.win_ptr);
	exit(0);
}

int	hook_close(t_rt *scene)
{
	printf("press red button\n");
	exit_program(scene);
	return (0);
}

int	hook_keyup(int keycode, t_rt *scene)
{
	if (keycode == KEY_ESC)
	{
		printf("press ESC\n");
		exit_program(scene);
	}
	return (0);
}
