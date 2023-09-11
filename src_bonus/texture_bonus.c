#include "initialize_bonus.h"
#include "utils_vec_bonus.h"

t_vec3	foo(t_tex *info, unsigned int u, unsigned int v)
{
	t_vec3	vec;
	char	*addr;

	addr = info->info.addr + (v * info->info.size_line \
							+ u * (info->info.bits_per_pixel / 8));
	vec.x = *(unsigned int *)addr >> 16 & 0xFF;
	vec.y = *(unsigned int *)addr >> 8 & 0xFF;
	vec.z = *(unsigned int *)addr & 0xFF;
	vec = vdiv_s(vec, 255.0);
	return (vec);
}

t_color	tex_get_color_value(t_rec *rec, const t_sp *sp)
{
	t_tex		*texture;
	t_tex		*normal;
	t_mapping	pos;
	t_color		color;
	t_vec3		p;

	texture = (t_tex *)rec->texture;
	normal = (t_tex *)rec->map;
	p = vsub_v(rec->intersect, sp->center);
	pos.u = 1 - (atan2(p.x, p.y) / (2 * M_PI) + 0.5);
	pos.v = 1 - (acos(p.z / sp->radius) / M_PI);
	pos.u *= texture->width;
	pos.v *= texture->height;
	if ((0 <= pos.u && pos.u < texture->width) \
		&& (0 <= pos.v && pos.v < texture->height))
	{
		color = foo(texture, pos.u, pos.v);
		rec->normal = vmul_v(foo(normal, pos.u, pos.v), rec->normal);
		return (color);
	}
	return (sp->color);
}
