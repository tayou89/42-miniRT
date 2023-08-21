#ifndef UTILS_VIEWPORT_H
# define UTILS_VIEWPORT_H

# include "utils_vec.h"

double	get_viewport_width(int fov, double focal_length);
double	get_viewport_height(double viewport_width);
t_point	get_viewport_center(t_point point, t_vec3 vec, double focal_length);
#endif
