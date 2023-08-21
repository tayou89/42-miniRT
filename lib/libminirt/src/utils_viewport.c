#include "../inc/utils_viewport.h"

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

t_point	get_viewport_center(t_point	point, t_vec3 vec, double focal_length)
{
	t_point	center_point;
	t_vec3	unit;
	t_vec3	center_vector;

	unit = vunit(vec);
	center_vector = vadd_s(unit, focal_length);
	center_point = padd_v(point, center_vector);
	return (center_point);
}
