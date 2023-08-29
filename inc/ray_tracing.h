#ifndef RAY_TRACING_H
# define RAY_TRACING_H

# include "datasheet.h"
# include "initialize.h"
# include "utils_vec.h"

void	draw_image_by_ray_tracing(t_mlx *mlx, t_data *data);
t_ray	get_primary_ray(t_camera camera, t_viewport viewport, t_pixel pixel);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
#endif
