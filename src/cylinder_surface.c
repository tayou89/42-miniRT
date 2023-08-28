#include "hit.h"

static void	set_record(t_rec *rec, t_cy *cy, t_ray ray)
{
	t_vec3	q;

	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, rec->t);
	q = vmul_s(cy->base, vdot(vsub_v(rec->intersect, cy->base), cy->normal));
	rec->normal = vunit(vsub_v(rec->intersect, q));
	if (vdot(rec->normal, ray.dir) > 0)
		rec->normal = vinverse(rec->normal);
	rec->albedo = cy->color;
}

static t_vec3	get_coef(t_cy *cy, t_ray ray)
{
	const t_vec3	w = vsub_v(ray.orig, cy->base);
	const double	wh = vdot(w, cy->normal);
	const double	vh = vdot(ray.dir, cy->normal);
	t_vec3			coef;

	coef.x = vlen(ray.dir) - (wh * wh);
	coef.y = vdot(ray.dir, w) - (vh * wh);
	coef.z = vlen(w) - (wh * wh) - (cy->radius * cy->radius);
	return (coef);
}

static int	cy_check_vaild(t_cy *cy, t_point p)
{
	t_point	cp;
	double	height;

	cp = vsub_v(p, cy->base);
	height = vdot(cp, vmul_s(cy->normal, cy->height));
	if (height < 0 || height > cy->height)
		return (FALSE);
	return (TRUE);
}

int	cy_hit_surface(t_cy *cy, t_ray ray, t_rec *rec)
{
	const t_vec3	coef = get_coef(cy, ray);
	const double	abs_vh = fabs(vdot(ray.dir, cy->normal));
	double			discrim;
	double			t;

	discrim = (coef.y * coef.y) - (coef.x * coef.z);
	if ((discrim < 0 && !double_equal(discrim, 0)) \
		|| (double_equal(discrim, 0) && abs_vh == 1.0))
		return (FALSE);
	discrim = sqrt(discrim);
	t = (-coef.y - discrim) / coef.x;
	if (t < rec->tmin || t > rec->tmax)
	{
		t = (-coef.y + discrim) / coef.x;
		if (t < rec->tmin || t > rec->tmax)
			return (FALSE);
	}
	if (cy_check_vaild(cy, ray_at(ray, t)) == FALSE)
		return (FALSE);
	rec->t = t;
	set_record(rec, cy, ray);
	return (TRUE);
}
