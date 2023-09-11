#include "initialize_bonus.h"
#include "utils_vec_bonus.h"

static t_vec3	get_convert_data(t_tex *info, unsigned int u, unsigned int v)
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
	if ((0 <= pos.u && pos.u < 1.0) && (0 <= pos.v && pos.v < 1.0))
	{
		color = get_convert_data(texture, \
				pos.u * texture->width, pos.v * texture->height);
		rec->normal = vmul_v(\
						get_convert_data(normal, \
						pos.u * normal->width, pos.v * normal->height), \
					rec->normal);
		rec->normal = vunit(rec->normal);
		return (color);
	}
	return (sp->color);
}
