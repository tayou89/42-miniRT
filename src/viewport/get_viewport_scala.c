#include "viewport.h"

double	get_viewport_width(int fov, double focal_length)
{
	double	width;
	double	half_width;

	half_width = focal_length * tan((double) fov / 2);
	width = half_width * 2;
	return (width);
}

double	get_viewport_height(double viewport_width)
{
	double	height;
	double	ratio;

	ratio  = (double) WIN_HEIGHT / (double) WIN_WIDTH;
	height = viewport_width * ratio;
	return (height);
}
