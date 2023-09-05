#ifndef IMAGE_BONUS_H
# define IMAGE_BONUS_H

# include "initialize_bonus.h"
# include "hit_bonus.h"

void	draw_image_by_ray_tracing(t_mlx *mlx, t_data *data);
int		phong_lighting(t_rec *rec, t_data *data);
int		color_get_trgb(int t, int r, int g, int b);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
#endif