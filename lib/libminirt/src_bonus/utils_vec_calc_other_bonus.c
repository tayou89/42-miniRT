/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec_calc_other_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:52 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:37:52 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_vec_bonus.h"

// 두 벡터를 내적한 결과를 반환(스칼라)
double	vdot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

// 두 벡터를 외적한 결과를 반환(벡터)
t_vec3	vcross(t_vec3 vec1, t_vec3 vec2)
{
	return (
		vset(
			vec1.y * vec2.z - vec1.z * vec2.y,
			vec1.z * vec2.x - vec1.x * vec2.z,
			vec1.x * vec2.y - vec1.y * vec2.x));
}

// 벡터의 길이에 제곱을 한 결과를 반환
double	vlen2(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

// 벡터의 길이를 반환
double	vlen(t_vec3 vec)
{
	return (sqrt(vlen2(vec)));
}

/*
* 벡터를 단위벡터로 정규화한 결과를 반환
* 만약 영벡터일 경우 해당 벡터를 그대로 반환 
*/
t_vec3	vunit(t_vec3 vec)
{
	return (vdiv_s(vec, vlen(vec)));
}
