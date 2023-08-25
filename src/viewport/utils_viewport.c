#include "utils_viewport.h"

double	get_viewport_width(int fov, double focal_length)
{
	double	width;
	double	half_width;

	half_width = focal_length * tan((double) fov / 2);
	width = half_width * 2;
	return (width);
}

double	get_viewport_height(double viewport_width)
{
	double	height;
	double	ratio;

	ratio  = (double) WIN_HEIGHT / (double) WIN_WIDTH;
	height = viewport_width * ratio;
	return (height);
}

t_point	get_viewport_center(t_camera camera, double focal_length)
{
	t_point	center_point;
	t_vec3	unit_vector;
	t_vec3	center_vector;

	unit_vector = vunit(camera.normal);
	center_vector = vmul_s(unit_vector, focal_length);
	center_point = vadd_v((t_vec3) camera.view_point, center_vector);
	return (center_point);
}

int	check_vectors_are_same(t_vec3 vec_1, t_vec3 vec_2)
{
	vec_1 = vunit(vec_1);
	vec_2 = vunit(vec_2);
	if (vec_1.x == vec_2.x && vec_1.y == vec_2.y && vec_1.z = vec_2.z)
		return (TRUE);
	else
		return (FALSE);
}
