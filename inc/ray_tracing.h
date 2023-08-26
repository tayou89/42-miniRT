#ifndef RAY_TRACING_H
# define RAY_TRACING_H

# include "datasheet.h"
# include "initialize.h"
# include "utils_vec.h"

typedef struct s_pixel
{
	t_point	point;
	t_color	color;
}	t_pixel;

void	draw_image_by_ray_tracing(t_data *data, t_mlx mlx);

t_ray	get_primary_ray(t_camera camera, t_viewport viewport, t_pixel pixel);

#endif
