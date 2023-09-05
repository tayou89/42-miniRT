#include "viewport_bonus.h"

static t_vec3	get_dir_vector(t_viewport *viewport, int dir);

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

t_point	get_viewport_corner(t_viewport *viewport, int dir_w, int dir_h)
{
	t_vec3	width_vector;
	t_vec3	height_vector;
	t_point	width_point;
	t_point	corner_point;

	width_vector = get_dir_vector(viewport, dir_w);
	width_point = vadd_v(viewport->center, vmul_s(width_vector, 0.5));
	height_vector = get_dir_vector(viewport, dir_h);
	corner_point = vadd_v(width_point, vmul_s(height_vector, 0.5));
	return (corner_point);
}

static t_vec3	get_dir_vector(t_viewport *viewport, int dir)
{
	t_vec3	dir_vector;

	if (dir == DIR_LEFT)
		dir_vector = vmul_s(viewport->right_vector, -1);
	else if (dir == DIR_RIGHT)
		dir_vector = viewport->right_vector;
	else if (dir == DIR_UP)
		dir_vector = vmul_s(viewport->down_vector, -1);
	else
		dir_vector = viewport->down_vector;
	return (dir_vector);
}

t_point	get_viewport_starting(t_viewport *viewport)
{
	t_point	starting;
	t_point	left_to_right;
	t_vec3	half_vector;

	half_vector = vmul_s(viewport->right_unit, 0.5);
	left_to_right = vadd_v(viewport->left_top, half_vector);
	half_vector = vmul_s(viewport->down_unit, 0.5);
	starting = vadd_v(left_to_right, half_vector);
	return (starting);
}
