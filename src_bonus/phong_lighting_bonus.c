#include "image_bonus.h"

static int	is_shadow(t_rec *rec, t_light *light, t_data *data)
{
	t_rec	temp;
	t_ray	ray;
	t_vec3	hitp;

	hitp = vadd_v(rec->intersect, vmul_s(rec->normal, EPSILON));
	temp = *rec;
	temp.tmax = vlen(vsub_v(light->point, temp.intersect));
	ray = ray_init(hitp, vsub_v(light->point, temp.intersect));
	if (hit_object(data, ray, &temp))
		return (TRUE);
	return (FALSE);
}

static t_color	get_ambient(t_ambient *amb)
{
	return (vmul_s(amb->color, amb->ratio));
}

static t_color	get_specula(t_rec *rec, t_light *light, t_ray ray)
{
	t_vec3	from_light;
	t_vec3	to_view;
	t_vec3	reflect;
	t_color	specula;
	double	t;

	from_light = vunit(vsub_v(rec->intersect, light->point));
	to_view = vunit(vmul_s(ray.dir, -1));
	reflect = vsub_v(from_light, \
				vmul_s(rec->normal, vdot(from_light, rec->normal) * 2.0));
	t = pow(fmax(vdot(to_view, reflect), 0.0), EXPONENT);
	specula = vmul_s(vmul_s(light->color, SHINY), t);
	return (specula);
}

static t_color	get_diffuse(t_rec *rec, t_light	*light)
{
	t_color	diffuse;
	t_vec3	dir;
	double	t;

	dir = vunit(vsub_v(light->point, rec->intersect));
	t = fmax(vdot(rec->normal, dir), 0.0);
	diffuse = vmul_s(light->color, t);
	return (diffuse);
}

int	phong_lighting(t_rec *rec, t_data *data, t_ray ray)
{
	t_list	*light;
	t_color	l_color;
	int		color;
	double	shadow;

	l_color = vset(0, 0, 0);
	light = data->light;
	while (light)
	{
		shadow = 1;
		if (is_shadow(rec, light->element, data))
			shadow = 0;
		l_color = vadd_v(l_color, get_diffuse(rec, light->element));
		l_color = vadd_v(l_color, get_specula(rec, light->element, ray));
		l_color = vmul_s(l_color, ((t_light *)(light->element))->ratio * 2);
		l_color = vmul_s(l_color, shadow);
		light = light->next;
	}
	l_color = vadd_v(l_color, get_ambient(&data->ambient));
	l_color = vmin(vmul_v(l_color, rec->albedo), vset(1, 1, 1));
	l_color = vmul_s(l_color, 255.999);
	color = color_get_trgb(0x0, l_color.x, l_color.y, l_color.z);
	return (color);
}
