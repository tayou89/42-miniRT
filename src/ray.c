#include "ray.h"

t_ray	ray_init(t_point orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_vec3	ray_primary(t_ray ray)
{
	t_ray	primary;
}

t_point	ray_at(t_ray ray, double t)
{
	t_point	point;

	point = vadd_v(ray.orig, vmul_s(ray.dir, t));
	return (point);
}
