#include "parsing.h"

t_sp	*make_sphere_node(t_info *info, t_parsing *parsing)
{
	t_sp	*sphere;

	sphere = (t_sp *) malloc(sizeof(t_sp));
	if (sphere == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	sphere->center = get_coordinate_data(info->coordinate, parsing);
	sphere->color = get_color_data(info->color, parsing);
	sphere->color = vdiv_s(sphere->color, 255.0);
	sphere->diameter = get_double(info->diameter, parsing);
	sphere->radius = sphere->diameter / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	return (sphere);
}

t_pl	*make_plane_node(t_info *info, t_parsing *parsing)
{
	t_pl	*plane;

	plane = (t_pl *) malloc(sizeof(t_pl));
	if (plane == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	plane->center = get_coordinate_data(info->coordinate, parsing);
	plane->normal = vunit(get_vector_data(info->vector, parsing));
	plane->color = get_color_data(info->color, parsing);
	plane->color = vdiv_s(plane->color, 255.0);
	return (plane);
}

t_cy	*make_cylinder_node(t_info *info, t_parsing *parsing)
{
	t_cy	*cylinder;

	cylinder = (t_cy *) malloc(sizeof(t_cy));
	if (cylinder == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	cylinder->center = get_coordinate_data(info->coordinate, parsing);
	cylinder->normal = vunit(get_vector_data(info->vector, parsing));
	cylinder->color = get_color_data(info->color, parsing);
	cylinder->color = vdiv_s(cylinder->color, 255.0);
	cylinder->diameter = get_double(info->diameter, parsing);
	cylinder->radius = cylinder->diameter / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = get_double(info->height, parsing);
	cylinder->top = vadd_v(cylinder->center, \
					vmul_s(cylinder->normal, cylinder->height / 2));
	cylinder->base = vadd_v(cylinder->center, \
					vmul_s(vinverse(cylinder->normal), cylinder->height / 2));
	return (cylinder);
}
