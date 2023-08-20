#include "parsing.h"

void	get_sphere_data(t_data *data, t_info *info, t_parsing *parsing)
{
	t_sp	*new_sphere;

	new_sphere = make_sphere_node(info, parsing);
	if (new_sphere == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	if (data->sphere == (void *) 0)
		data->sphere = new_sphere;
	else
		data->sphere = add_sphere_node(new_sphere, data->sphere);
}

void	get_plane_data(t_data *data, t_info *info, t_parsing *parsing)
{
	t_pl	*new_plane;

	new_plane = make_plane_node(info, parsing);
	if (new_plane == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	if (data->plane == (void *) 0)
		data->plane = new_plane;
	else
		data->plane = add_plane_node(new_plane, data->plane);
}

void	get_cylinder_data(t_data *data, t_info *info, t_parsing *parsing)
{
	t_cy	*new_cylinder;

	new_cylinder = make_cylinder_node(info, parsing);
	if (new_cylinder == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	if (data->cylinder == (void *) 0)
		data->cylinder = new_cylinder;
	else
		data->cylinder = add_cylinder_node(new_cylinder, data->cylinder);
}
