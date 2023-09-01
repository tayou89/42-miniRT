#include "hit.h"

static void	set_hit_func(int (*hit_func[])(t_list *, t_ray, t_rec *))
{
	hit_func[PLANE] = pl_hit;
	hit_func[SPHERE] = sp_hit;
	hit_func[CYLINDER] = cy_hit;
}

int	hit_object(t_data *data, t_ray primary, t_rec *rec)
{
	t_list	*world;
	int		is_hit;
	int		(*hit_func[3])(t_list *, t_ray, t_rec *);

	set_hit_func(hit_func);
	world = data->obj;
	is_hit = FALSE;
	while (world)
	{
		if (hit_func[world->type](world, primary, rec))
			is_hit = TRUE;
		world = world->next;
	}
	return (is_hit);
}
