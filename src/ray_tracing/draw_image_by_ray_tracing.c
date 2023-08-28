#include "ray_tracing.h"
#include "parsing.h"

void	draw_image_by_ray_tracing(t_world *data)
{
	t_pixel	pixel;
	t_ray	primary_ray;

	pixel.point.y = 0;
	while (pixel.point.y < WIN_HEIGHT)
	{
		pixel.point.x = 0;
		while (pixel.point.x < WIN_WIDTH)
		{
			primary_ray = get_primary_ray(data->camera, data->viewport, pixel);
			pixel.point.x++;
		}
		pixel.point.y++;
	}
}
