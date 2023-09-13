/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_surface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:38:10 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:38:11 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

static void	set_record(t_rec *rec, t_cy *cy, t_ray ray)
{
	t_vec3	cp;
	t_vec3	q;

	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, rec->t);
	cp = vsub_v(rec->intersect, cy->base);
	q = vmul_s(cy->normal, vdot(cp, cy->normal));
	rec->normal = vunit(vsub_v(cp, q));
	if (vdot(rec->normal, ray.dir) > 0)
		rec->normal = vinverse(rec->normal);
	rec->albedo = cy->color;
}

static int	check_valid_height(t_cy *cy, t_ray ray, double t)
{
	t_vec3	inter;
	t_vec3	cp;
	double	height;

	inter = ray_at(ray, t);
	cp = vsub_v(inter, cy->base);
	height = vdot(cp, vunit(vsub_v(cy->top, cy->base)));
	if (height < 0 || height > cy->height)
		return (FALSE);
	return (TRUE);
}

static t_vec3	get_coef(t_cy *cy, t_ray ray)
{
	const t_vec3	w = vsub_v(ray.orig, cy->base);
	const double	vh = vdot(ray.dir, cy->normal);
	const double	wh = vdot(w, cy->normal);
	t_vec3			coef;

	coef.x = vlen2(ray.dir) - (vh * vh);
	coef.y = vdot(ray.dir, w) - (vh * wh);
	coef.z = vlen2(w) - (wh * wh) - cy->radius2;
	return (coef);
}

int	cy_hit_surface(t_cy *cy, t_ray ray, t_rec *rec)
{
	const t_vec3	coef = get_coef(cy, ray);
	const double	same_dir = fabs(vdot(ray.dir, cy->normal));
	double			discrim;
	double			t;

	discrim = (coef.y * coef.y) - (coef.x * coef.z);
	if ((discrim < 0 && !double_equal(discrim, 0)) \
	|| (double_equal(discrim, 0) && double_equal(same_dir, 1.0)))
		return (FALSE);
	discrim = sqrt(discrim);
	t = (-coef.y - discrim) / coef.x;
	if (t < rec->tmin || t > rec->tmax)
	{
		t = (-coef.y + discrim) / coef.x;
		if (t < rec->tmin || t > rec->tmax)
			return (FALSE);
	}
	if (!check_valid_height(cy, ray, t))
		return (FALSE);
	rec->t = t;
	set_record(rec, cy, ray);
	return (TRUE);
}
