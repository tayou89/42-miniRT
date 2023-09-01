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
	t_vec3	color;
	int		(*hit_func[3])(t_list *, t_ray, t_rec *);

	color = vset(0, 0, 0);
	set_hit_func(hit_func);
	world = data->obj;
	while (world)
	{
		if (hit_func[world->type](world, primary, rec))
			color = phong_lighting(rec, data);
		world = world->next;
	}
	color = vmul_s(color, 255.999);
	return (color_get_trgb(0x0, (int)color.x, (int)color.y, (int)color.z));
}
