/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:38:44 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:38:45 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

static void	set_record(t_rec *rec, const t_sp *sp, t_ray ray)
{
	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, rec->t);
	rec->normal = vunit(vsub_v(rec->intersect, sp->center));
	if (vdot(rec->normal, ray.dir) > 0)
		rec->normal = vinverse(rec->normal);
	rec->albedo = sp->color;
}

static t_vec3	get_coef(t_vec3 osubc, t_ray ray, const t_sp *sp)
{
	t_vec3	coef;

	coef.x = vlen2(ray.dir);
	coef.y = vdot(osubc, ray.dir);
	coef.z = vlen2(osubc) - sp->radius2;
	return (coef);
}

int	sp_hit(t_list *obj, t_ray ray, t_rec *rec)
{
	const t_sp		*sp = obj->element;
	const t_vec3	osubc = vsub_v(ray.orig, sp->center);
	const t_vec3	coef = get_coef(osubc, ray, sp);
	double			discrim;
	double			t;

	discrim = (coef.y * coef.y) - (coef.x * coef.z);
	if (!double_equal(discrim, 0) && discrim < 0)
		return (FALSE);
	discrim = sqrt(discrim);
	t = (-coef.y - discrim) / coef.x;
	if (t < rec->tmin || t > rec->tmax)
	{
		t = (-coef.y + discrim) / coef.x;
		if (t < rec->tmin || t > rec->tmax)
			return (FALSE);
	}
	rec->t = t;
	set_record(rec, sp, ray);
	return (TRUE);
}
