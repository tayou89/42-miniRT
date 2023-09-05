#ifndef RAY_H
# define RAY_H
# include "utils_vec.h"

t_ray	ray_init(t_point orig, t_vec3 dir);
t_point	ray_at(t_ray ray, double t);
t_ray	get_primary_ray(t_camera camera, t_viewport viewport, t_pixel pixel);
#endif