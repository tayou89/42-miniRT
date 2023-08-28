#include "hit.h"

/*
*	평면에 히트했는지 판별
*	평면의 법선벡터, 광선의 방향벡터 내적의 결과
*	0이 아닐 경우 : 교점이 1개 -> hit
*	0일 경우 : 광선이 평면과 평행하다
*	1) 광선은 평면의 일부가 아님, 교점이 0개
*	2) 광선은 평면의 일부, 교점이 무한개
*/
static void	set_record(t_rec *rec, t_pl *pl, t_ray ray)
{
	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, rec->t);
	rec->normal = vunit(pl->normal);
	if (vdot(rec->normal, ray.dir) > 0)
		rec->normal = vinverse(rec->normal);
	rec->albedo = pl->color;
}

int	pl_hit(t_pl *pl, t_ray ray, t_rec *rec)
{
	double	intersect;
	double	t;

	intersect = vdot(pl->normal, ray.dir);
	if (double_equal(intersect, 0))
		return (FALSE);
	t = vdot(vsub_v(pl->center, ray.orig), pl->normal) / intersect;
	if (t < rec->tmin || t > rec->tmax)
		return (FALSE);
	rec->t = t;
	set_record(rec, pl, ray);
	return (TRUE);
}
