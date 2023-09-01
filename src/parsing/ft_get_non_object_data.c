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
	data->light.color = get_color_data(info->color, parsing);
	data->light.color = vdiv_s(data->light.color, 255.0);
}
