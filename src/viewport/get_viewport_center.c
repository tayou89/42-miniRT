#include "../../inc/viewport.h"

void	get_viewport_center(t_data *data)
{
	t_camera	camera;
	t_vec3		camera_unit_vector;

	camera = data->camera;
	camera_unit_vector = vunit(camera->normal);
	data->viewport->center = padd_v(camera->view_point, camera_unit_vector);
}
