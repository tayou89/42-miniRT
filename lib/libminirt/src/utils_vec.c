#include "utils_vec.h"

// 값이 0인 벡터를 반환
t_vec3	vinit(void)
{
	t_vec3	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

// 입력받은 값으로 초기화한 벡터를 반환
t_vec3	vset(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec3	vinverse(t_vec3 vec)
{
	vec.x = -vec.x;
	vec.y = -vec.y;
	vec.z = -vec.z;
	return (vec);
}
