#include "hit.h"

int	double_equal(double x, double y)
{
	if (fabs(x - y) <= EPSILON)
		return (TRUE);
	return (FALSE);
}

static void	set_hit_func(int (*hit_func[])(t_list *, t_ray, t_rec *))
{
	hit_func[PLANE] = pl_hit;
	hit_func[SPHERE] = sp_hit;
	hit_func[CYLINDER] = cy_hit;
}

int	hit_object(t_list *world, t_ray primary, t_rec *rec)
{
	t_vec3	color;
	int		(*hit_func[3])(t_list *, t_ray, t_rec *);

	color = vset(0, 0, 0);
	set_hit_func(hit_func);
	while (world)
	{
		if (hit_func[world->type](world, primary, rec))
			color = rec->albedo;
		world = world->next;
	}
	return (color_get_trgb(0x0, color.x, color.y, color.z));
}
