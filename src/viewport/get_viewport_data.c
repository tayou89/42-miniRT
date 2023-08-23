#include "viewport.h"

static void	make_normal_camera(t_camera *virtual, t_camera origin);
static void	make_virtual_viewport(t_viewport *virtual, t_camera temp);
static void	calculate_viewport_scala(t_viewport *virtual, t_camera temp);
static void	calculate_viewport_point(t_viewport *virtual, t_camera temp);

void	get_viewport_data(t_data *data)
{ 
	t_camera	normal_camera;
	t_viewport	normal_viewport;

	make_normal_camera(&normal_camera, data->camera);
	make_virtual_viewport(&normal_viewport, normal_camera);
	calculate_viewport_data(data, normal_viewport, normal_camera);
}

static void	make_normal_camera(t_camera *normal, t_camera origin)
{
	normal->view_point = pset(0, 0, 0);
	normal->normal = vset(0, 0, 1);
	normal->fov = origin.fov;
}

static void	make_virtual_viewport(t_viewport *normal, t_camera temp)
{
	calculate_viewport_scala(normal, temp);
	calculate_viewport_point(normal, temp);
}

static void	calculate_viewport_scala(t_viewport *normal, t_camera temp)
{
	normal->width = get_viewport_width(temp.fov, FOCAL_LENGTH);
	normal->height = get_viewport_height(normal->width);
}

static void	calculate_viewport_point(t_viewport *normal, t_camera temp)
{
	double	width;
	double	height;

	width = normal->width;
	height = normal->height;
	normal->center = \
		get_viewport_center(temp.view_point, temp.normal, FOCAL_LENGTH);
	normal->left_top = \
		pset((width / 2) * -1, height / 2, FOCAL_LENGTH);
	normal->right_top = \
		pset(width / 2, height / 2, FOCAL_LENGTH);
	normal->left_bottom = \
		pset((width / 2) * -1, (height / 2) * -1, FOCAL_LENGTH);
}
