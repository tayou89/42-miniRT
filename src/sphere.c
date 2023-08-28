#include "hit.h"
/*
*	구에 히트 했는지 판별
*	결과값 > 0 : 교점이 2개 -> hit
*	결과값 = 0 : 교점이 1개, 원에 접함 -> hit
*	결과값 < 0 : 교점이 0개 -> no hit
*/
static void	set_record(t_rec *rec, t_sp *sp, t_ray ray)
{
	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, rec->t);
	rec->normal = vunit(vsub_v(rec->intersect, sp->center));
	if (vdot(rec->normal, ray.dir) > 0)
		rec->normal = vinverse(rec->normal);
	rec->albedo = sp->color;
}

static t_vec3	get_coef(t_vec3 osubc, t_ray ray, t_sp *sp)
{
	t_vec3	coef;

	coef.x = vlen(ray.dir);
	coef.y = vdot(osubc, ray.dir);
	coef.z = vlen(osubc) - (sp->radius * sp->radius);
	return (coef);
}

int	sp_hit(t_sp *sp, t_ray ray, t_rec *rec)
{
	const t_vec3	osubc = vsub_v(ray.orig, sp->center);
	const t_vec3	coef = get_coef(osubc, ray, sp);
	double			discrim;
	double			t;

	discrim = (coef.b * coef.b) - (coef.a * coef.c);
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
