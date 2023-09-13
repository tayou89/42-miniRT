/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:40 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:37:40 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	vsame(t_vec3 vec1, t_vec3 vec2)
{
	vec1 = vunit(vec1);
	vec2 = vunit(vec2);
	if (!double_equal(vec1.x, vec2.x))
		return (FALSE);
	if (!double_equal(vec1.y, vec2.y))
		return (FALSE);
	if (!double_equal(vec1.z, vec2.z))
		return (FALSE);
	return (TRUE);
}

t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}
