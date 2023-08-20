#include "../inc/utils_vec.h"

t_point	padd_v(t_point point, t_vec3 vec)
{
	point.x += vec.x;
	point.y += vec.y;
	point.z += vec.z;
	return (point);
}
