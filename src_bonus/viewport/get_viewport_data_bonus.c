/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_viewport_data_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:32:03 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:32:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport_bonus.h"

static void	get_viewport_initial_data(t_viewport *viewport, t_camera camera);
static void	get_viewport_vector(t_viewport *viewport, t_camera camera);
static void	get_viewport_point(t_viewport *viewport);

void	get_viewport_data(t_viewport *viewport, t_camera camera)
{
	get_viewport_initial_data(viewport, camera);
	get_viewport_vector(viewport, camera);
	get_viewport_point(viewport);
}

static void	get_viewport_initial_data(t_viewport *viewport, t_camera camera)
{
	viewport->center = get_viewport_center(camera, FOCAL_LENGTH);
	viewport->width = get_viewport_width(camera.fov, FOCAL_LENGTH);
	viewport->height = get_viewport_height(viewport->width);
}

static void	get_viewport_vector(t_viewport *viewport, t_camera camera)
{
	viewport->axis_vector = get_viewport_axis_vector(camera.normal);
	viewport->right_vector = get_viewport_right_vector(viewport, camera);
	viewport->down_vector = get_viewport_down_vector(viewport, camera);
	viewport->right_unit = \
		get_viewport_unit_vector(viewport->right_vector, DIR_RIGHT);
	viewport->down_unit = \
		get_viewport_unit_vector(viewport->down_vector, DIR_DOWN);
}

static void	get_viewport_point(t_viewport *viewport)
{
	viewport->left_top = get_viewport_corner(viewport, DIR_LEFT, DIR_UP);
	viewport->starting = get_viewport_starting(viewport);
}
