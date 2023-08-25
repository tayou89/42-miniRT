#include "viewport.h"

static void	make_normal_camera(t_camera *virtual, t_camera origin);
static void	make_virtual_viewport(t_viewport *virtual, t_camera temp);
static void	calculate_viewport_scala(t_viewport *virtual, t_camera temp);
static void	calculate_viewport_point(t_viewport *virtual, t_camera temp);

void	get_viewport_data(t_data *data)
{
	data->viewport.center = get_viewport_center(data->camera, FOCAL_LENGTH);
	data->viewport.width = get_viewport_width(data->camera.fov, FOCAL_LENGTH);
	data->viewport.height = get_viewport_height(data->viewport.width);
	get_viewport_vector(&data->viewport, data->camera);
}

void	get_viewport_vector(t_viewport *viewport, t_camera camera)
{
	t_vec3	pivot_vector;

	pivot_vector = define_pivot_vector(camera.normal);
}

t_vec3	difine_pivot_vector(t_vec3 camera_vector);
{
	t_vec3	pivot_vector;
	t_vec3	inverse_vector;

	pivot_vector = vset(1, 0, 0);
	inverse_vector = vmul_s(camera_vector, -1);
	if (check_vector_if_same(camera_vector, pivot_vector) == TRUE)
		return (vset(0, 0, -1));
	else if (check_vector_if_same(inverse_vector, pivot_vector) == TRUE)
		return (vset(0, 0, 1));
	else
		return (pivot_vector);
}
