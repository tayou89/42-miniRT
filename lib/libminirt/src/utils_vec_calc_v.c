/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec_calc_v.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:37 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:37:38 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_vec.h"

// 두개의 벡터를 덧셈한 결과를 반환
t_vec3	vadd_v(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return (vec1);
}

// 두개의 벡터를 뺄셈한 결과를 반환
t_vec3	vsub_v(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return (vec1);
}

// 두개의 벡터를 곱셈한 결과를 반환
t_vec3	vmul_v(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return (vec1);
}
