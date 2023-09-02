#include "ray_tracing.h"
#include "parsing.h"
#include "hit.h"
#include "ftmlx.h"

void	draw_image_by_ray_tracing(t_mlx *mlx, t_data *data)
{
	t_pixel	pixel;
	t_ray	primary_ray;
	t_rec	rec;
	int		color;

	pixel.point.y = 0;
	while (pixel.point.y < WIN_HEIGHT)
	{
		pixel.point.x = 0;
		while (pixel.point.x < WIN_WIDTH)
		{
			color = 0;
			rec.tmin = 0;
			rec.tmax = INFINITY;
			primary_ray = get_primary_ray(data->camera, data->viewport, pixel);
			if (hit_object(data, primary_ray, &rec))
				color = phong_lighting(&rec, data);
			put_pixel(mlx, pixel.point.x, pixel.point.y, color);
			pixel.point.x++;
		}
		pixel.point.y++;
	}
}
