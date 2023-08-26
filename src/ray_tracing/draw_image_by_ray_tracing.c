#include "ray_tracing.h"

int		check_primary_ray_hit(void);
t_color	get_pixel_color(void);
t_color	get_background_color(t_pixel pixel);
void	draw_color_on_pixel(t_pixel pixel, t_mlx mlx);

void	draw_image_by_ray_tracing(t_data *data, t_mlx mlx)
{
	t_pixel	pixel;
	t_ray	primary_ray;

	pixel.point.y = 0;
	while (pixel.point.y < WIN_HEIGHT)
	{
		pixel.point.x = 0;
		while (pixel.point.x < WIN_WIDTH)
		{
			primary_ray = get_primary_ray(data->camera, data->viewport, pixel); //크기 1인 단위벡터
			pixel.color = get_background_color(pixel);
			draw_color_on_pixel(pixel, mlx);
			pixel.point.x++;
		}
		pixel.point.y++;
	}
}

int	check_primary_ray_hit(void)
{
	return (FALSE);
}

t_color	get_pixel_color(void)
{
	t_color	color;

	color = vset(255, 255, 255);
	return (color);
}

t_color	get_background_color(t_pixel pixel)
{
	t_color	color;

	color = vset((double) pixel.point.y / 10, (double) pixel.point.y / 10, 255);
	return (color);
}

void	draw_color_on_pixel(t_pixel pixel, t_mlx mlx)
{
	int	color;

	color = ((int) pixel.color.x << 16 | (int) pixel.color.y << 8 | (int) pixel.color.z);
	mlx_pixel_put(mlx.ptr.mlx_ptr, mlx.ptr.win_ptr, pixel.point.x, pixel.point.y, color);
}
