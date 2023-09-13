/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:38:41 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:38:41 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_point	get_target_point(t_viewport viewport, t_pixel pixel);

t_ray	ray_init(t_point orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_point	ray_at(t_ray ray, double t)
{
	t_point	point;

	point = vadd_v(ray.orig, vmul_s(ray.dir, t));
	return (point);
}

t_ray	get_primary_ray(t_camera camera, t_viewport viewport, t_pixel pixel)
{
	t_ray	primary_ray;
	t_point	target_point;

	primary_ray.orig = camera.view_point;
	target_point = get_target_point(viewport, pixel);
	primary_ray.dir = vunit(vsub_v(target_point, primary_ray.orig));
	return (primary_ray);
}

static t_point	get_target_point(t_viewport viewport, t_pixel pixel)
{
	t_point	target_point;
	t_point	right_from_starting;
	t_vec3	right_vector;
	t_vec3	down_vector;

	right_vector = vmul_s(viewport.right_unit, pixel.point.x);
	down_vector = vmul_s(viewport.down_unit, pixel.point.y);
	right_from_starting = vadd_v(viewport.starting, right_vector);
	target_point = vadd_v(right_from_starting, down_vector);
	return (target_point);
}
