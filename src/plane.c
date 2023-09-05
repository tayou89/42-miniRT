#include "hit.h"

static void	set_record(t_rec *rec, t_pl *pl, t_ray ray)
{
	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, rec->t);
	rec->normal = vunit(pl->normal);
	if (vdot(rec->normal, ray.dir) > 0)
		rec->normal = vinverse(rec->normal);
	rec->albedo = pl->color;
}

int	pl_hit(t_list *obj, t_ray ray, t_rec *rec)
{
	t_pl	*pl;
	double	intersect;
	double	t;

	pl = obj->element;
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
