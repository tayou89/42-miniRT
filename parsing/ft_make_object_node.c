#include "parsing.h"

t_sp	*make_sphere_node(t_info *info, t_parsing *parsing)
{
	t_sp	*sphere;

	sphere = (t_sp *) malloc(sizeof(t_sp));
	if (sphere == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	sphere->center = get_coordinate_data(info->coordinate, parsing);
	sphere->color = get_color_data(info->color, parsing);
	sphere->diameter = get_double(info->diameter, parsing);
	sphere->radius = diameter / 2;
	sphere->next = (void *) 0;
	sphere->prev = (void *) 0;
	return (sphere);
}

t_pl	*make_plane_node(t_info *info, t_parsing *parsing)
{
	t_pl	*plane;

	plane = (t_pl *) malloc(sizeof(t_pl));
	if (plane == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	plane->center = get_coordinate_data(info->coordinate, parsing);
	plane->normal = get_vector_data(info->vector, parsing);
	plane->color = get_color_data(info->color, parsing);
	plane->next = (void *) 0;
	plane->prev = (void *) 0;
	return (plane);
}

t_cy	*make_cylinder_node(t_info *info, t_parsing *parsing)
{
	t_cy	*cylinder;

	cylinder = (t_cy *) malloc(sizeof(t_cy));
	if (cylinder == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	cylinder->center = get_coordinate_data(info->coordinate, parsing);
	cylinder->normal = get_vector_data(info->vector, parsing);
	cylinder->color = get_color_data(info->color, parsing);
	cylinder->diameter = get_double(info->diameter, parsing);
	cylinder->radius = cylinder->diameter / 2;
	cylinder->height = get_double(info->height, parsing);
	cylinder->next = (void *) 0;
	cylinder->prev = (void *) 0;
	return (cylinder);
}
