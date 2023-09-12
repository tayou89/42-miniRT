#include "parsing_bonus.h"

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
	if (sphere->diameter <= 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	sphere->radius = sphere->diameter / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	sphere->checker.exist = FALSE;
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
	cylinder->height = get_double(info->height, parsing);
	if (cylinder->diameter <= 0 || cylinder->height <= 0)
		ft_parsing_error(DATA_ERROR, 1, parsing);
	cylinder->radius = cylinder->diameter / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->top = vadd_v(cylinder->center, \
					vmul_s(cylinder->normal, cylinder->height / 2));
	cylinder->base = vadd_v(cylinder->center, \
					vmul_s(vinverse(cylinder->normal), cylinder->height / 2));
	return (cylinder);
}

t_co	*make_cone_node(t_info *info, t_parsing *parsing)
{
	t_co	*cone;

	cone = (t_co *) malloc(sizeof(t_co));
	if (cone == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	cone->center = get_coordinate_data(info->coordinate, parsing);
	cone->normal = vunit(get_vector_data(info->vector, parsing));
	cone->color = get_color_data(info->color, parsing);
	cone->color = vdiv_s(cone->color, 255.0);
	cone->diameter = get_double(info->diameter, parsing);
	cone->height = get_double(info->height, parsing);
	if (cone->diameter <= 0 || cone->height <= 0)
		ft_parsing_error(DATA_ERROR, 1, parsing);
	cone->radius = cone->diameter / 2;
	cone->radius2 = cone->radius * cone->radius;
	cone->top = vadd_v(cone->center, vmul_s(cone->normal, cone->height / 2.0));
	cone->height_unit = vinverse(cone->normal);
	cone->height_vector = vmul_s(cone->height_unit, cone->height);
	cone->disk_center = vadd_v(cone->center, vmul_s(cone->height_vector, 0.5));
	cone->cosine = cone->height / sqrt(cone->radius2 + pow(cone->height, 2));
	return (cone);
}

t_sp	*make_checker_node(t_info *info, t_parsing *parsing)
{
	t_sp	*sphere;

	sphere = (t_sp *) malloc(sizeof(t_sp));
	if (sphere == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	sphere->center = get_coordinate_data(info->coordinate, parsing);
	sphere->diameter = get_double(info->diameter, parsing);
	if (sphere->diameter <= 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	sphere->radius = sphere->diameter / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	sphere->checker.exist = TRUE;
	sphere->checker.width = get_integer(info->width, parsing);
	if (sphere->checker.width <= 0 || sphere->checker.width > 100)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	sphere->checker.length = get_integer(info->length, parsing);
	if (sphere->checker.length <= 0 || sphere->checker.length > 100)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	sphere->checker.color_1 = get_color_data(info->color, parsing);
	sphere->checker.color_1 = vdiv_s(sphere->checker.color_1, 255.0);
	sphere->checker.color_2 = get_color_data(info->vector, parsing);
	sphere->checker.color_2 = vdiv_s(sphere->checker.color_2, 255.0);
	return (sphere);
}
