#include "hit_bonus.h"

static void	set_record(t_rec *rec, t_cy *cy, t_ray ray)
{
	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, rec->t);
	rec->normal = vunit(cy->normal);
	if (vdot(rec->normal, ray.dir) > 0)
		rec->normal = vinverse(rec->normal);
	rec->albedo = cy->color;
}

static int	cy_hit_disk(t_cy *cy, t_ray ray, t_rec *rec, t_vec3 center)
{
	double	intersect;
	double	t;

	intersect = vdot(cy->normal, ray.dir);
	if (double_equal(intersect, 0))
		return (FALSE);
	t = vdot(vsub_v(center, ray.orig), cy->normal) / intersect;
	if (t < rec->tmin || t > rec->tmax)
		return (FALSE);
	if (vlen2(vsub_v(ray_at(ray, t), center)) > cy->radius * cy->radius)
		return (FALSE);
	rec->t = t;
	set_record(rec, cy, ray);
	return (TRUE);
}

int	cy_hit(t_list *obj, t_ray ray, t_rec *rec)
{
	t_cy	*cy;
	int		result;

	cy = obj->element;
	result = FALSE;
	result += cy_hit_disk(cy, ray, rec, cy->base);
	result += cy_hit_disk(cy, ray, rec, cy->top);
	result += cy_hit_surface(cy, ray, rec);
	return (result);
}
