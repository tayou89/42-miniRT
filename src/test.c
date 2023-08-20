#include <math.h>
#include <stdio.h>

int	main(void)
{
	double	tangent;
	double	double_tangent;
	double	window_width;
	double	window_height;
	double	viewport_width;
	double	viewport_height;
	double	window_leftx;
	double	window_topy;

	window_width;
	tangent = tan(35);
	double_tangent = tangent * 2;
	viewport_width = double_tangent;
	printf("tangent: %.10f\n", tangent);
	printf("double_tangent: %.10f\n", double_tangent);
	printf("double_tangent/ width: %.10f\n", double_tangent / 1920);
	return (0);
}
