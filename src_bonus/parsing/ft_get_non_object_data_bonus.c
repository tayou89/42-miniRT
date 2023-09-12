#include "parsing_bonus.h"

static t_light	*make_light_node(t_info *info, t_parsing *parsing);

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
	t_light	*new_light;
	t_list	*node;

	new_light = make_light_node(info, parsing);
	if (new_light == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	node = create_node(new_light, LIGHT);
	if (node == NULL)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	push_back(&data->light, node);
}

static t_light	*make_light_node(t_info *info, t_parsing *parsing)
{
	t_light	*light;

	light = (t_light *) malloc(sizeof(t_light));
	if (light == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	light->point = get_coordinate_data(info->coordinate, parsing);
	light->ratio = get_ratio_data(info->ratio, parsing);
	light->color = get_color_data(info->color, parsing);
	light->color = vdiv_s(light->color, 255.0);
	return (light);
}
