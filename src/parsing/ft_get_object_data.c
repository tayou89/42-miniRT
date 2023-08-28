#include "parsing.h"

void	get_sphere_data(t_world *data, t_info *info, t_parsing *parsing)
{
	t_sp	*new_sphere;

	new_sphere = make_sphere_node(info, parsing);
	if (new_sphere == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	push_back(&data->obj, new_sphere);
}

void	get_plane_data(t_world *data, t_info *info, t_parsing *parsing)
{
	t_pl	*new_plane;

	new_plane = make_plane_node(info, parsing);
	if (new_plane == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	push_back(&data->obj, new_plane);
}

void	get_cylinder_data(t_world *data, t_info *info, t_parsing *parsing)
{
	t_cy	*new_cylinder;

	new_cylinder = make_cylinder_node(info, parsing);
	if (new_cylinder == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	push_back(&data->obj, new_cylinder);
}
