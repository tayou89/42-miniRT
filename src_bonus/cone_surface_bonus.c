#include "hit_bonus.h"

static int		get_ray_size(double *size, t_ray ray, t_co *cone, t_rec *rec);
static t_vec3	get_quadratic_formula_coefficient(t_ray ray, t_co *cone);
static int		check_contact_on_surface(t_point contact, t_co *cone);
static void		set_record(t_rec *rec, t_co *cone, t_ray ray, double ray_size);

int	co_hit_surface(t_co *cone, t_ray ray, t_rec *rec)
{
	double	ray_size;
	t_point	contact;

	if (get_ray_size(&ray_size, ray, cone, rec) == FALSE)
		return (FALSE);
	contact = ray_at(ray, ray_size);
	if (check_contact_on_surface(contact, cone) == FALSE)
		return (FALSE);
	set_record(rec, cone, ray, ray_size);
	return (TRUE);
}

static int	get_ray_size(double *size, t_ray ray, t_co *cone, t_rec *rec)
{
	double	ray_size;
	t_vec3	coefficient;
	double	discriminant;

	coefficient = get_quadratic_formula_coefficient(ray, cone);
	discriminant = pow(coefficient.y, 2) - (coefficient.x * coefficient.z);
	if (double_equal(discriminant, 0) == FALSE && discriminant < 0)
		return (FALSE);
	if (double_equal(discriminant, 0) == TRUE \
		&& cone->cosine == fabs(vdot(ray.dir, cone->height_unit)))
		return (FALSE);
	ray_size = (-coefficient.y - sqrt(discriminant)) / coefficient.x;
	if (ray_size < rec->tmin || ray_size > rec->tmax)
	{
		ray_size = (-coefficient.y + sqrt(discriminant)) / coefficient.x;
		if (ray_size < rec->tmin || ray_size > rec->tmax)
			return (FALSE);
	}
	*size = ray_size;
	return (TRUE);
}

static t_vec3	get_quadratic_formula_coefficient(t_ray ray, t_co *cone)
{
	t_vec3			coefficient;
	double			term_a;
	const double	term_b = (cone->radius2 / vlen2(cone->height_vector)) + 1;
	double			term_c;
	const t_vec3	top_to_ray_orig = vsub_v(ray.orig, cone->top);

	term_a = vdot(ray.dir, ray.dir);
	term_c = vdot(ray.dir, cone->height_unit) \
			* vdot(ray.dir, cone->height_unit);
	coefficient.x = term_a - (term_b * term_c);
	term_a = vdot(ray.dir, top_to_ray_orig);
	term_c = vdot(ray.dir, cone->height_unit) \
			* vdot(top_to_ray_orig, cone->height_unit);
	coefficient.y = term_a - (term_b * term_c);
	term_a = vdot(top_to_ray_orig, top_to_ray_orig);
	term_c = vdot(top_to_ray_orig, cone->height_unit) \
			* vdot(top_to_ray_orig, cone->height_unit);
	coefficient.z = term_a - (term_b * term_c);
	return (coefficient);
}

static int	check_contact_on_surface(t_point contact, t_co *cone)
{
	t_vec3	top_to_contact;
	double	contact_height;

	top_to_contact = vsub_v(contact, cone->top);
	contact_height = vdot(top_to_contact, cone->height_unit);
	if (double_equal(contact_height, 0) == FALSE && contact_height < 0)
		return (FALSE);
	else if (contact_height > cone->height)
		return (FALSE);
	else
		return (TRUE);
}

static void	set_record(t_rec *rec, t_co *cone, t_ray ray, double ray_size)
{
	t_vec3	top_to_contact;
	t_vec3	vertical_vector;

	rec->t = ray_size;
	rec->tmax = rec->t;
	rec->intersect = ray_at(ray, ray_size);
	top_to_contact = vsub_v(rec->intersect, cone->top);
	vertical_vector = vcross(cone->height_unit, top_to_contact);
	rec->normal = vunit(vcross(vertical_vector, top_to_contact));
	if (vdot(rec->normal, ray.dir) > 0)
		rec->normal = vinverse(rec->normal);
	rec->albedo = cone->color;
}
