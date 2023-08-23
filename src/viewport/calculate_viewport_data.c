#include "viewport.h"

static t_diff	calculate_diff_from_camera(t_camera origin, t_camera temp);
static void		calculate_corner(t_viewport *viewport, t_diff diff);
static void		calculate_vector(t_viewport *viewport);
static t_point	get_corner(t_vec3 point, t_diff diff);

void	calculate_viewport_data(t_data *data, t_viewport normal, t_camera temp)
{
	t_viewport	viewport;
	t_camera	camera;
	t_diff		diff;

	camera = data->camera;
	diff = calculate_diff_from_camera(data->camera, temp);
	viewport.width = normal.width;
	viewport.height = normal.height;
	calculate_corner(&viewport, normal, diff);
	calculate_vector(&viewport);
	data->viewport = viewport;
}

static t_diff	calculate_diff_from_camera(t_camera origin, t_camera temp)
{
	t_diff	diff;

	diff.vector = vsub_v(origin.normal, temp.normal);
	diff.point = vsub_v((t_vec3) origin.view_point, (t_vec3) temp.view_point);
	return (diff);
}

static void	calculate_corner(t_viewport *viewport, t_viewport normal, t_diff diff)
{
	viewport->left_top = get_corner((t_vec3) normal->left_top, diff);
	viewport->right_top = get_corner((t_vec3) normal->right_top, diff);
	viewport->left_bottom = get_corner((t_vec3) normal.left_bottom, diff);
}

static t_point	get_corner(t_vec3 point, t_diff diff)
{
	t_vec3	corner_vector;
	t_vec3	first_result;

	first_result = vadd_v(point, diff.vector);
	corner_vector = vadd_v(first_result, diff.point);
	return ((t_point) corner_vector);
}

static void	calculate_viewport_vector(t_viewport *viewport)
{
	viewport->horizontal = \
		vsub_v((t_vec3) viewport->left_top, (t_vec3) viewport->right_top);
	viewport->vertical = \
		vsub_v((t_vec3) viewport->left_top, (t_vec3) viewport->left_bottom);
}
