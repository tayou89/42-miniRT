#ifndef RAY_H
# define RAY_H
# include "datasheet.h"
# include "utils_vec.h"

t_ray	ray_init(t_point orig, t_vec3 dir);
t_vec3	ray_primary(t_ray ray);
t_point	ray_at(t_ray ray, double t);
#endif