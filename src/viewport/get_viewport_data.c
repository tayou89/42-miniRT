#include "../../inc/viewport.h"

void	get_viewport_data(t_data *data)
{
	get_viewport_width(data);
	get_viewport_center(data);
}

void	get_viewport_width(t_data *data)
{
	t_camera	camera;
	double		tangent;

	camera = data->camera;
	tangent = tan(camera->fov / 2);
	data->viewport.width = tangent * 2;
}

void	get_viewport_center(t_data *data)
{
	t_camera	camera;
	t_vec3		camera_unit_vector;

	camera = data->camera;
	camera_unit_vector = vunit(camera->normal);
	data->viewport.center = padd_v(camera->view_point, camera_unit_vector);
}
