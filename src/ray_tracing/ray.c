#include "ray_tracing.h"

t_point	get_target_point(t_viewport viewport, t_pixel pixel);

t_ray	get_primary_ray(t_camera camera, t_viewport viewport, t_pixel pixel)
{
	t_ray	primary_ray;
	t_point	target_point;

	primary_ray.orig = camera.view_point;
	target_point = get_target_point(viewport, pixel);
	primary_ray.dir = vsub_v(target_point, primary_ray.orig);
	primary_ray.dir = vunit(primary_ray.dir);
	return (primary_ray);
}

t_point	get_target_point(t_viewport viewport, t_pixel pixel)
{
	t_point	target_point;
	t_point	right_from_starting;
	t_vec3	right_vector;
	t_vec3	down_vector;

	right_vector = vmul_s(viewport.right_unit, pixel.point.x);
	down_vector = vmul_s(viewport.down_unit, pixel.point.y);
	right_from_starting = vadd_v(viewport.starting, right_vector);
	target_point = vadd_v(right_from_starting, down_vector);
	return (target_point);
}
