#include "image_bonus.h"

int	color_get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < WIN_WIDTH) && (0 <= y && y < WIN_HEIGHT))
	{
		dst = mlx->img.addr + (y * mlx->img.size_line \
							+ x * (mlx->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

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
				color = phong_lighting(&rec, data, primary_ray);
			put_pixel(mlx, pixel.point.x, pixel.point.y, color);
			pixel.point.x++;
		}
		pixel.point.y++;
	}
}

t_color	get_checker_color(const t_sp *sphere, t_point intersect)
{
	t_color		checker_color;
	t_mapping	mapping;
	int			width;
	int			length;
	int			round_sum;

	intersect = vsub_v(intersect, sphere->center);
	mapping.u = 0.5 + atan2(intersect.z, intersect.x) / M_PI;
	mapping.v = 0.5 - asin(intersect.y / sphere->radius) / M_PI;
	width = sphere->checker.width;
	length = sphere->checker.length;
	round_sum = (int)(round(width * mapping.u) + round(length * mapping.v));
	if (round_sum % 2 == 0)
		checker_color = sphere->checker.color_1;
	else
		checker_color = sphere->checker.color_2;
	return (checker_color);
}
