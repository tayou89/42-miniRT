#include "hit_bonus.h"

static int	co_hit_disk(t_co *cone, t_ray ray, t_rec *rec);
static int	get_ray_size(double *ray_size, t_ray ray, t_co *cone, t_rec *rec);
static int	check_contact_on_disk(t_point contact, t_co *cone);
static void	set_hit_record(t_rec *rec, t_co *cone, t_ray ray, double ray_size);

int	co_hit(t_list *object, t_ray ray, t_rec *rec)
{
	t_co	*cone;
	int		hit_result;

	cone = object->element;
	hit_result = FALSE;
	hit_result += co_hit_disk(cone, ray, rec);
	hit_result += co_hit_surface(cone, ray, rec);
	return (hit_result);
}

static int	co_hit_disk(t_co *cone, t_ray ray, t_rec *rec)
{
	double	ray_size;
	t_point	contact;

	if (vdot(ray.dir, cone->normal) == 0)
		return (FALSE);
	if (get_ray_size(&ray_size, ray, cone, rec) == FALSE)
		return (FALSE);
	contact = ray_at(ray, ray_size);
	if (check_contact_on_disk(contact, cone) == FALSE)
		return (FALSE);
	set_hit_record(rec, cone, ray, ray_size);
	return (TRUE);
}

static int	get_ray_size(double *ray_size, t_ray ray, t_co *cone, t_rec *rec)
{
	double	formula_numerator;
	double	formula_denominator;

	formula_numerator = vdot(vsub_v(ray.orig, cone->disk_center), cone->normal);
	formula_denominator = vdot(ray.dir, cone->normal);
	*ray_size = formula_numerator / formula_denominator * -1;
	if (*ray_size < rec->tmin || *ray_size > rec->tmax)
		return (FALSE);
	else
		return (TRUE);
}

static int	check_contact_on_disk(t_point contact, t_co *cone)
{
	double	length_to_center;

	length_to_center = vlen(vsub_v(contact, cone->disk_center));
	if (length_to_center > cone->radius)
		return (FALSE);
	else
		return (TRUE);
}

static void	set_hit_record(t_rec *rec, t_co *cone, t_ray ray, double ray_size)
{
	rec->t = ray_size;
	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, ray_size);
	if (vdot(ray.dir, cone->normal) < 0)
		rec->normal = cone->normal;
	else
		rec->normal = vinverse(cone->normal);
	rec->albedo = cone->color;
}
