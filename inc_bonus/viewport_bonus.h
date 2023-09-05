#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "initialize_bonus.h"
# include "utils_vec_bonus.h"

# define FOCAL_LENGTH	1

# define DIR_UP		0
# define DIR_DOWN	1
# define DIR_LEFT	2
# define DIR_RIGHT	3

void	get_viewport_data(t_viewport *viewport, t_camera camera);

double	get_viewport_width(int fov, double focal_length);
double	get_viewport_height(double viewport_width);

t_point	get_viewport_center(t_camera camera, double focal_length);
t_point	get_viewport_corner(t_viewport *viewport, int dir_w, int dir_h);
t_point	get_viewport_starting(t_viewport *viewport);

t_vec3	get_viewport_axis_vector(t_vec3 camera_vector);
t_vec3	get_viewport_right_vector(t_viewport *viewport, t_camera camera);
t_vec3	get_viewport_down_vector(t_viewport *viewport, t_camera camera);
t_vec3	get_viewport_unit_vector(t_vec3 vector, int dir);

#endif
