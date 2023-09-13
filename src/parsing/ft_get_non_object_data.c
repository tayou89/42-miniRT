/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_non_object_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:26 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:28:29 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_ambient_data(t_data *data, t_info *info, t_parsing *parsing)
{
	data->ambient.ratio = get_ratio_data(info->ratio, parsing);
	data->ambient.color = get_color_data(info->color, parsing);
	data->ambient.color = vdiv_s(data->ambient.color, 255.0);
}

void	get_camera_data(t_data *data, t_info *info, t_parsing *parsing)
{
	data->camera.view_point = get_coordinate_data(info->coordinate, parsing);
	data->camera.normal = vunit(get_vector_data(info->vector, parsing));
	data->camera.fov = get_fov_data(info->fov, parsing);
}

void	get_light_data(t_data *data, t_info *info, t_parsing *parsing)
{
	data->light.point = get_coordinate_data(info->coordinate, parsing);
	data->light.ratio = get_ratio_data(info->ratio, parsing);
	data->light.color = vset(1, 1, 1);
}
