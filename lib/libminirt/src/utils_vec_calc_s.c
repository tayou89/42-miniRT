/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec_calc_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:33 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:37:34 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_vec.h"

// 벡터를 스칼라값만큼 더한 결과를 반환
t_vec3	vadd_s(t_vec3 vec, double s)
{
	vec.x += s;
	vec.y += s;
	vec.z += s;
	return (vec);
}

// 벡터를 스칼라값만큼 뺀 결과를 반환
t_vec3	vsub_s(t_vec3 vec, double s)
{
	vec.x -= s;
	vec.y -= s;
	vec.z -= s;
	return (vec);
}

// 벡터를 스칼라값만큼 곱한 결과를 반환
t_vec3	vmul_s(t_vec3 vec, double s)
{
	vec.x *= s;
	vec.y *= s;
	vec.z *= s;
	return (vec);
}

// 벡터를 스칼라값만큼 나눈 결과를 반환
t_vec3	vdiv_s(t_vec3 vec, double s)
{
	if (s != 0)
	{
		vec.x /= s;
		vec.y /= s;
		vec.z /= s;
	}
	return (vec);
}
