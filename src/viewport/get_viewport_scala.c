#include "viewport.h"

double	get_viewport_width(int fov, double focal_length)
{
	double	width;
	double	half_width;
	double	half_fov;
	double	radian;

	half_fov = (double)fov / 2.0;
	radian = half_fov * (M_PI / 180);
	half_width = focal_length * tan(radian);
	width = half_width * 2;
	return (width);
}

double	get_viewport_height(double viewport_width)
{
	double	height;
	double	ratio;

	ratio = (double) WIN_HEIGHT / (double) WIN_WIDTH;
	height = viewport_width * ratio;
	return (height);
}
