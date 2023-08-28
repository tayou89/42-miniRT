#ifndef HIT_H
# define HIT_H

# include "ray.h"

# define EPSILON 1e-6

int	double_equal(double x, double y);
int	cy_hit_surface(t_cy *cy, t_ray ray, t_rec *rec);
#endif