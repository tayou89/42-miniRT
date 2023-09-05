#include "viewport_bonus.h"

static t_vec3	resize_vector(t_vec3 vector_to_resize, double size);

t_vec3	get_viewport_axis_vector(t_vec3 camera_vector)
{
	t_vec3	axis_vector;
	t_vec3	inverse_vector;

	axis_vector = vset(0, 1, 0);
	inverse_vector = vmul_s(camera_vector, -1);
	if (vsame(camera_vector, axis_vector) == TRUE
		|| vsame(inverse_vector, axis_vector) == TRUE)
		axis_vector = vset(0, 0, -1);
	return (axis_vector);
}

t_vec3	get_viewport_right_vector(t_viewport *viewport, t_camera camera)
{
	t_vec3	right_vector;

	right_vector = vcross(viewport->axis_vector, camera.normal);
	right_vector = resize_vector(right_vector, viewport->width);
	return (right_vector);
}

t_vec3	get_viewport_down_vector(t_viewport *viewport, t_camera camera)
{
	t_vec3	down_vector;

	down_vector = vcross(viewport->right_vector, camera.normal);
	down_vector = resize_vector(down_vector, viewport->height);
	return (down_vector);
}

t_vec3	get_viewport_unit_vector(t_vec3 vector, int dir)
{
	t_vec3	viewport_unit_vector;

	if (dir == DIR_LEFT || dir == DIR_RIGHT)
		viewport_unit_vector = vmul_s(vector, (double) 1 / WIN_WIDTH);
	else
		viewport_unit_vector = vmul_s(vector, (double) 1 / WIN_HEIGHT);
	return (viewport_unit_vector);
}

static t_vec3	resize_vector(t_vec3 vector_to_resize, double size)
{
	t_vec3	unit_vector;
	t_vec3	resized_vector;

	unit_vector = vunit(vector_to_resize);
	resized_vector = vmul_s(unit_vector, size);
	return (resized_vector);
}
