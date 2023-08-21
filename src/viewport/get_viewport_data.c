/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_viewport_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:38:00 by tayou             #+#    #+#             */
/*   Updated: 2023/08/21 13:56:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/viewport.h"

void	get_viewport_data(t_data *data)
{
	t_camera	virtual_camera;
	t_viewport	virtual_viewport;
	t_vec3		diff;

	make_virtual_camera(&virtual_camera, data->camera);
	make_virtual_viewport(&virtual_viewport, virtual_camera);
}

void	make_virtual_camera(t_camera *virtual, t_camera origin)
{
	virtual->view_point = pset(0, 0, 0);
	virtual->normal = vset(0, 0, 1);
	virtual->fov = origin.fov;
}

void	make_virtual_viewport(t_viewport *virtual, t_camera temp)
{
	double	focal_length;

	focal_length = 1;
	virtual->width = get_viewport_width(temp->fov, focal_length);
	virtual->height = get_viewport_height(virtual->width);
	virtual->center = \
	get_viewport_center(temp->view_point, temp->normal, focal_length);
	virtual->left_top = \
	pset((virtual->width / 2) * -1, 
}

